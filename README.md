# libft-pain

![Pain](https://user-images.githubusercontent.com/72362902/182051399-ea2525d5-42c4-4e36-b9b3-3b782a36d3e0.png)


Libft tester trying to make sure no test cases get unnoticed and focussing on a good user experience :P

## Usage

libft folder inside the test directory:
```
├─ libft-pain/
│  ├─ pain.sh
│  ├─ libft/
│  │  ├─ ft_atoi.c
│  │  ├─ ft_itoa.c
│  │  ├─ ft_split.c
```
If you are not familiar with cmake **run pain.sh**

Install C++ TestMate extension for Vscode!

Click on the button on the left: ![image](https://user-images.githubusercontent.com/72362902/182051765-d90b3c5a-bc29-4a7c-a55f-285372e11f11.png)

Don't forget to recompile once you edit your libft files!

## Advanced Usage

in the build directory, you can run ctest
to run a specific test, with output you can run ctest -L split --output-on-failure
For a full list of options, check out: https://cmake.org/cmake/help/latest/manual/ctest.1.html

build/Testing/LastTest.log
shows you the detailed output of the last test

## HELP it does not show any tests

1. No main inside the libft directory
2. Open libft-pain folder in Vscode or the extension has trouble finding the tests

## Leaks on ft_split

A lot of people have a hard time figuring out why/where ft_split is leaking, so here the solution:

```
Malloc array of pointers to strings

If array == Null  // Allocation failed
	return NULL;

while (splits left)
{
	Malloc string
	If (string == null)  // Allocation failed
	{
		free ALL previously allocated strings
		free array
		return NULL
	}
	Fill string
}
return array
```
