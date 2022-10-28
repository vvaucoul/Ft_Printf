# Ft_Printf

Rewrite of the **printf** function.<br>

## Available Options

- **%c**: Display character.
- **%s**: Display string.
- **%d** / **%i**: Display integer.
- **%u**: Display unsigned integer.
- **%x** / **%X**: Display hexadecimal number lowercase or uppercase.
- **%p**: Display pointer address.
- **%%**: Display % character.

##Attributes

- **+**: Display spaces after argument.
- **-**: Display spaces before argument.
- **0**: Fill size of zero by size - argument length.
- **.**: Use precision.

## Usage

- Clone Repository
```bash
git clone https://vvaucoul/Ft_Printf && cd Ft_Printf
```

- Compilation
```bash
make
```

## Prototype
```C
int ft_printf(const char *str, ...);
```
