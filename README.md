# ASJ

AssetSplitJoin splits large files into smaller chunks, and joins them. Useful for checking large assets into version control.

## Motivation
- Project has some BIG 100MB+ files
- Wanna put on Git, can't because of size
- Wanna track it in the same repo though!
- By splitting up the file into sub-100MB parts, can be tracked on Git!

## Implementation (?)
Files needed:
- SJ executable
- SJ list
	- SJ List is a bunch of relative paths, sorted alphabetically for ease of lookup (binary search!)

Unity vs. Non-Unity (DIY)
Unity version is a wrapper of the DIY version, it just uses certain arguments when running the underlying executable!!

Split files should be in a folder of their own, I feel. Just gotta remove the folder when joining back.

Put it on vcpkg and Unity Asset Store as well? So that other devs can used it?

## Research (?) Notes
- needs command line options
- remember that an assignment had them
- check all assignments
- find the assignment with command line options
- read the doc pdf to find out how it was done
- turns out it was a whole separate library
- barely on the first page of google results for it, not even on github
- some chinese dude makes a github repo just to have it available on vcpkg, respect!
- see if vcpkg can really work on linux (and also mac)
- videos don't really help
- trust that microsoft's Learn pages actualy do the job
- look up cmakepresets documentation and it looks cross-platform-enough XD
