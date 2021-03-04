# blif2bench
A .blif to .bench converter

## Usage
### Python
#### Dependency installation
`pip install toml`
#### Instructions
1. Configure the working directory, input blif file and output bench file in the `config.toml`
2. Run `python main.py`
3. The program will output the .bench file in the working directory

### C++
#### Instructions
1. Configure the working directory, input blif file and output bench file in the `config.toml`
2. Get the latest release from https://github.com/EdrichVeburg/blif2bench/releases
3. Run `./blif2bench <path to config.toml>`
4. The program will output the .bench file in the working directory

