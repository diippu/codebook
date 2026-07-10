{
    "shell_cmd": "g++ -std=c++17 \"$file_name\" -o \"$file_base_name\" && ./\"$file_base_name\" < input.txt > output.txt",
    "selector": "source.cpp",
    "shell": true,
    "working_dir": "$file_path"
}
