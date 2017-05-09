To create a new project in CSS you must follow the steps in F2837xS
 Firmware Development Package User's Guide in Section 2.2 and BE AWARE THAT:
-1 the wizard setup for the creation of a new projects creates a linker
 command list if you don't look in Advanced Options in the wizard popup window.
 If you specify another linker command list in the project's Properties 
 you'll get errors
-2 remember that the .asm and .c files that you are adding as a link
 MUST remain in the project's root folder, otherwise the makefile won't
 find them
