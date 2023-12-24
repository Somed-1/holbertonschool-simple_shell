# Basic Shell

**A simplified shell that offers a foundational command-line experience.**
![](https://github.com/VoiceOfDarkness/holbertonschool-simple_shell/blob/main/rz8a1F.gif)

## Key Functionalities

* **User-Friendly Prompt:** Displays a clear prompt and patiently awaits user input.
* **One-Line Commands:** Accepts straightforward commands, each ending with a newline. No semicolons, pipes, redirections, or other intricate features are necessary.
* **Single-Line Execution:** Processes commands exclusively within a single line, without passing arguments to programs.
* **Error Handling:** Gracefully manages scenarios where executables are not found, printing informative error messages and returning the prompt.
* **End-of-File Mastery:** Seamlessly handles "End of file" conditions (Ctrl+D).

## Current Limitations

* **PATH Independence:** Operates without reliance on the PATH environment variable.
* **No Built-Ins:** Does not implement built-in commands.
* **Special Character Avoidance:** Refrains from handling special characters such as ", ', `, \, *, &, and #.
* **Cursor Stationarity:** Maintains a steady cursor position.
* **Argument-Free Operation:** Executes commands without the complexity of arguments.

## Usage

To use the Basic Shell, simply type in a command and press Enter. The command line will always end with a newline. For example, to run the `ls` command, you would type the following:

The Basic Shell will then display a list of files in the current directory.

To exit the Basic Shell, press Ctrl+D.

## Authors

**Creators:**

* Abbasov Magomed ([Somed-1](https://github.com/somed-1/))
* Abil Samedov ([VoiceOfDarkness](https://github.com/VoiceOfDarkness/))

**Special Credits:**

> You really don't need to know, but here's the link if you're curious: [link](https://www.youtube.com/watch?v=hvL1339luv0)
