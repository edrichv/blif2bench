import blifparse
import toml

config = toml.load('../config.toml')
files_conf = config['Files']
in_blif = files_conf['work_dir'] + files_conf['in_blif']
out_blif = in_blif.replace('.blif','.bench')

blifparse.to_bench(in_blif,out_blif, config['BBGT'])