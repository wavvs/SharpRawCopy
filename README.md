# SharpRawCopy

SharpRawCopy is a C# wrapper for [rawccopy](https://github.com/dr-anoroc/rawccopy). Copy files off NTFS volumes by using low level disk reading method. 

Uses [DLLFromMemory-net](https://github.com/schellingb/DLLFromMemory-net) to load unmanaged library from memory.

## Build

Compiled RawCCopy DLL file is located in [SharpRawCopy/Resource1](https://github.com/wavvs/SharpRawCopy/tree/main/SharpRawCopy/Resource1). 

Build SharpRawCopy (.NET 4.0 is required):

```powershell
$ cd SharpRawCopy/
$ msbuild /p:Configuration=Release /p:Platform=x64
```

## Examples

Copy SAM file (as Administrator):

```
$ SharpRawCopy.exe /FileNamePath:C:\Windows\System32\Config\SAM /OutputPath:%TEMP%
```

See [rawccopy](https://github.com/dr-anoroc/rawccopy) README for more examples.