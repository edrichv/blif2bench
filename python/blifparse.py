NEWLINE = "\n"

class Gate:
    def __init__(self, gate_type, inputs, output):
        self.__gate_type = gate_type
        self.__inputs = inputs
        self.__output = output

    def inputs(self):
        return self.__inputs

    def output(self):
        return self.__output

    def gate_type(self):
        return self.__gate_type

    def get_printable_line(self):
        return [self.__gate_type, self.__inputs, self.__output]

class Bliffile:
    def __init__(self, path, config):
        self.__path = path
        self.__file_cursor = 0
        self.__config = config
        self.__gate_list = list()
        self.__inputs = list()
        self.__outputs = list()
        self.__split_dict = dict()
        # Store all file lines in list
        self.__file_lines = open(path, 'r').readlines()
        self.__final_line_idx = len(self.__file_lines)-1
        # Remove \r and \n from lines
        for i in range(0, self.__final_line_idx + 1):
            self.__file_lines[i] = self.__file_lines[i].replace('\r','')
            self.__file_lines[i] = self.__file_lines[i].replace('\n','')
        self.__parse()

    def as_dict(self):
        ret = dict()
        ret['model_name'] = self.__model_name
        ret['inputs'] = self.__inputs
        ret['outputs'] = self.__outputs
        ret['gate_list'] = self.__gate_list
        ret['split_dict'] = self.__split_dict
        return ret
        
    def prev_line(self):
        if self.__file_cursor > 0:
            self.__file_cursor -= 1
    
    def next_line(self):
        if self.__file_cursor < self.__final_line_idx:
            self.__file_cursor += 1
        
    def print_contents(self):
        for line in self.__file_lines:
            print(line)

    def print_gate_list(self):
        for gate in self.__gate_list:
            print(gate.get_printable_line())

    def get_split_dict(self):
        return self.__split_dict

    def __conditioned(self, line):
        # make all characters lowercase
        conditioned = line.lower()
        # remove duplicate spaces
        conditioned = " ".join(conditioned.split())
        return conditioned

    def __parse(self):
        for line in self.__file_lines:
            line = self.__conditioned(line)
            line_components = line.split(' ')
            command = line_components[0]
            if command == '.gate':
                g_in = []
                g_out = []
                temp = str(line_components[1]).upper()
                for comp in line_components[2:]:
                    if 'in' in comp:
                        g_in.append(comp.split('=')[1])
                    elif 'out' in comp:
                        g_out.append(comp.split('=')[1])
                if temp == 'SPLIT':
                    for output in g_out:
                        self.__split_dict[output] = g_in[0]
                else:
                    g_type = self.__config[temp]
                    self.__gate_list.append(Gate(g_type,g_in,g_out[0]))
            elif command == '.model':
                self.__model_name = line_components[1]
            elif command == '.inputs':
                for input_i in line_components[1:]:
                    if input_i != 'clk':
                        self.__inputs.append(input_i)
            elif command == '.outputs':
                self.__outputs = line_components[1:]
            elif command == '.end':
                return
            else : pass

def to_bench(in_path, out_path, config):
    bf = Bliffile(in_path, config)
    bf_data = bf.as_dict()
    split_dict = bf_data['split_dict']

    out_lines =list()
    
    # Write model name
    out_lines.append("# " + bf_data['model_name'])
    # Write inputs
    for node in bf_data['inputs']:
        out_lines.append(NEWLINE + "input(" + node + ")")
    # Write outputs
    for node in bf_data['outputs']:
        out_lines.append(NEWLINE + "output(" + node + ")")
    # Write gate assignment
    for gate in bf_data['gate_list']:
        out = NEWLINE + gate.output() + " = " + gate.gate_type() + "("
        # Add all gate inputs
        for g_in_i in gate.inputs():
            if g_in_i in split_dict.keys(): g_in_i = split_dict[g_in_i]
            out += g_in_i + ","
        # Remove unwanted "," and end line
        out = out[:-1] + ")"
        out_lines.append(out)

    __write_file(out_path, out_lines)

def __write_file(path, lines):
    f = open(path,"w")
    f.writelines(lines)
    f.close()