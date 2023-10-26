# C Language Learn And Action

## Command Line 执行方式

```sh
gcc -std=c11 [filename].c

# windows
.\a.exe
```

### mac
```sh
clang [filename].c
# or
gcc [filename].c
./a.out 
```

## VSCode launch 配置
- `"program": "${workspaceFolder}/chapter-2/a.exe",`
  - 根据需要进行修改

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(Windows) 启动",
      "type": "cppvsdbg",
      "request": "launch",
      "program": "${workspaceFolder}/chapter-2/a.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "console": "externalTerminal"
    }
  ]
}

```
