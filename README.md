# ft_printf - 42KL ✨

## 💡About The Project

Welcome to my `ft_printf` project! It's my simplified version of `printf` in C, based on the [**project guidelines**](https://github.com/appinha/42cursus/tree/master/_PDFs).
The goal here is to learn about **variadic arguments** and **formatted output**.

- - -

<!-- ## 🎯 Why I Did It -->
## 🤔 Why I Did It

I wanted to understand how `printf` works in C. It's a function we use all the time, but I was curious to know what's going on under the hood.
***And although it's part of the 42KL curriculum, I'm happy that I completed it***. I learned a lot and had fun exploring these new concepts, working with my friends along the way.

- - -

## 🎉 Project Overview

`ft_printf` supports basic formatting options and handles variadic arguments,
with support for conversion specifiers such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

<br />
Example:

```c
ft_printf("Hello, %s! You have %d new messages.\n", "Max", 5);
```

Output:

```bash
Hello, Max! You have 5 new messages.
```

- - -

## 🚀 Getting Started

Here's how you can get `ft_printf` up and running on your machine:

<br />

1. **Clone the repository**
   
```bash
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf
```

<hr />

2. **Build the project**

&nbsp;&nbsp;&nbsp; > _Running `make` will compile the project and create a `lftprintf.a` library._

```bash
make
```

<hr />

3. **Link the library**

&nbsp;&nbsp;&nbsp; > _To use the `lftprintf.a` library in your code, include its header:_

```c
#include "ft_printf.h"
```

<br />

&nbsp;&nbsp;&nbsp; > _When compiling your code, add the required flags to link the library:_

```bash
-I path/to/ft_printf.h -L path/to/libftprintf.a -lftprintf
```

- - -

## 🐞 Known Issues and Bugs

- **Limited Format Specifiers:** `ft_printf` does not support all the format specifiers of the standard `printf`.
- **Edge Cases:** Certain edge cases may not be handled perfectly.

- - -

## 📷 Project Result

![Screenshot of *ychng* result from the 42KL cursus ft_printf project.](screenshot/ft_printf_result.png)

