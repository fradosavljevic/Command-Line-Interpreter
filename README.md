# CLI Interpreter

A C++ command-line interpreter supporting command parsing, I/O redirection,
pipelines, and batch execution.

## Overview

This project implements a command-line interpreter in C++.

The interpreter processes user input through a lexer/parser pipeline and
executes commands using a context-based execution model.

## Features

-  Command parsing
-  Built-in commands
-  Input redirection
-  Output redirection
-  Command pipelines
-  Batch/script execution
-  Interactive mode
-  Error handling
-  Context management
-  Stream-based I/O

## Architecture

The interpreter is organized into several main components:

<p align="center">
  <img src="./assets/pipeline.png" width="420" alt="Opis slike">
</p>

## Supported Commands

* **`echo`**
    * **Format:** `echo [argument]`
    * **Description:** Forwards characters from its input stream to its output stream without any modifications.

* **`prompt`**
    * **Format:** `prompt argument`
    * **Description:** Changes (sets) the interpreter command prompt character/string to the sequence of characters provided as an argument enclosed in quotes.

* **`time`**
    * **Format:** `time`
    * **Description:** Outputs the current time from the real-time system clock to its output character stream.

* **`date`**
    * **Format:** `date`
    * **Description:** Outputs the current date from the real-time system clock to its output character stream.

* **`touch`**
    * **Format:** `touch filename`
    * **Description:** Creates a file with the specified name and empty content in the current directory. If the file already exists, it prints an error message and has no other effect.

* **`truncate`**
    * **Format:** `truncate filename`
    * **Description:** Deletes the content of the file with the specified name from the current directory.

* **`rm`**
    * **Format:** `rm filename`
    * **Description:** Deletes the file with the specified name (removes the file from the file system) from the current directory.

* **`wc`**
    * **Format:** `wc -opt [argument]`
    * **Description:** Counts words or all characters in the text loaded from the input character stream and prints the count to its output stream.
    * **Options:**
        * `-w` – Counts words
        * `-c` – Counts all characters

* **`tr`**
    * **Format:** `tr [argument] –what [with]`
    * **Description:** In the text read from the input stream, finds all occurrences of the character sequence `what` (enclosed in quotes after the `-` sign) and replaces them with the character sequence `with` (enclosed in quotes). If `with` is not provided, the occurrences are simply removed.

* **`head`**
    * **Format:** `head -ncount [argument]`
    * **Description:** Transfers the first few lines of text read from the input stream to its output stream and ignores the remaining content.
    * **Options:** The mandatory `-n` option is followed immediately by up to 5 decimal digits specifying the number of leading lines.

* **`batch`**
    * **Format:** `batch filename`
    * **Description:** Interprets the content of the input file with the specified name as a sequence of command lines (batch processing) and executes them sequentially.