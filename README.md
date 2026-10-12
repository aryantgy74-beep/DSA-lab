# DSA Lab Sheets 04–07 — C++ Solutions

These beginner-friendly C++ programs are organized by topic and compile as separate programs on GDB Online or a local C++ compiler.

## Files
- `LinkedList.cpp` — singly linked list: insert at beginning/end/position, delete at beginning/end/position, display, search, count, min/max, reverse, sort.
- `Stack.cpp` — array stack: push, pop, peek, display, overflow demonstration, string reversal, balanced brackets, infix-to-postfix and infix-to-prefix (single-character operands).
- `Queue.cpp` — array queue: enqueue, dequeue, peek, display, count, search, min/max, reverse display order, plus circular queue operations.
- `Tree.cpp` — BST insertion, search, inorder/preorder/postorder traversals, deletion (leaf/one child/two children using inorder successor), height, total node count, leaf count.

## Run on GDB Online
1. Open https://www.onlinegdb.com/online_c++_compiler
2. Open one `.cpp` file from this folder and copy its contents into the editor.
3. Click **Run**. Use the menu in the terminal to test the operations.
4. Run each `.cpp` separately; each file has its own `main()`.

## Upload to GitHub
1. Create a repository, for example `DSA-Lab-Solutions`.
2. Click **Add file → Upload files**.
3. Upload the four `.cpp` files and this `README.md`.
4. Click **Commit changes**.

## Notes
- Positions in the linked-list program are 1-based.
- The infix converters assume single-character operands and standard operators; they are teaching examples, not full expression parsers.
- The queue and stack use arrays. The circular queue is included in `Queue.cpp`.
- These are combined menu-driven implementations covering the main operations from the four uploaded lab sheets. If your instructor specifically requires one separate file per numbered exercise, split the relevant function into its own `main()` program before submitting.
