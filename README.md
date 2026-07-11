# BashScripts — Automation Projects (Resume Portfolio)

A focused collection of practical **Bash automation projects** that solve common command-line and file-management tasks.

These projects highlight my ability to write clean shell scripts, validate user input, use Linux utilities effectively, and build reusable CLI tools.

---

## Tech Stack

- **Language:** Bash (Shell)
- **Core Tools:** `find`, `wc`, `mv`, regex pattern matching, ANSI terminal formatting
- **Environment:** Linux terminal / Unix-like systems

---

## Projects

### 1) Directory File Counter
**Path:** `Directory_File_Counter/DIRcount.sh`

A CLI utility that lists files in a target directory and reports the total file count.

**Key highlights**
- Accepts directory path as a command-line argument
- Validates missing/invalid input with clear error handling
- Prints full file paths using `find`
- Computes total file count using `wc -l`
- Improves UX with colorized output and terminal progress effects

**Sample usage**
```bash
bash Directory_File_Counter/DIRcount.sh /path/to/directory
```

**Resume impact statement**
Built a robust file-inspection script that automates directory auditing and demonstrates strong command-line scripting fundamentals.

---

### 2) File Renamer
**Path:** `File_Renamer/rename_File.sh`

A batch renaming tool that standardizes filenames in a directory using a custom base name and extension.

**Key highlights**
- Takes directory path, new base name, and extension as input
- Validates directory existence before processing
- Iterates through files and renames sequentially (`name_1.ext`, `name_2.ext`, ...)
- Uses safe move operations with quoted variables for reliability
- Displays per-file rename logs and total renamed count

**Sample usage**
```bash
bash File_Renamer/rename_File.sh /path/to/files invoice pdf
```

**Resume impact statement**
Developed a bulk file-standardization script that reduces manual renaming effort and improves consistency in file organization workflows.

---

### 3) Country Calling Code Detector
**Path:** `Country_calling_code/script_Number.sh`

A regex-driven parser that reads phone numbers from a file and identifies their country/region based on calling prefixes.

**Key highlights**
- Reads records line-by-line from `number.txt`
- Classifies numbers for multiple regions (India, USA/Canada, UK, Germany, Australia, Japan, France, Brazil, Russia, South Africa, Spain, Italy, China)
- Uses regex validation for format and length checks
- Separates valid known patterns, unknown regions, and invalid numbers
- Provides colorized categorized terminal output

**Sample usage**
```bash
cd Country_calling_code
bash script_Number.sh
```

**Resume impact statement**
Implemented a pattern-matching utility using shell regex to classify telecom data, demonstrating practical text-processing and validation skills.

---

## What This Repository Demonstrates

- Command-line automation and scripting discipline
- Input validation and defensive programming in shell
- Text processing with regex and shell parameter expansion
- File-system operations and batch processing
- Building practical developer tools with user-friendly terminal output

---

## Author

**Hrishikesh D.**

If you'd like, I can also create a **one-line, ATS-friendly project summary** version tailored for your resume's Projects section.