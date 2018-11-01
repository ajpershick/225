#!/usr/bin/env python
import subprocess
import sys,os

passed = 0

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)


# Yes, these should be in a for loop.
# Run test 1
sys.stdout.write("Running test 1... ");
subprocess.call("./hello_world < 1.in > 1.out",shell=True)
rt = subprocess.call("diff -b 1.out 1.gt",shell=True);
if rt == 0:
    passed += 1
    sys.stdout.write("passed\n");
else:
    sys.stdout.write("failed\n");

# Run test 2
sys.stdout.write("Running test 2... ")
subprocess.call("./hello_world < 2.in > 2.out",shell=True)
rt = subprocess.call("diff -b 2.out 2.gt",shell=True);
if rt == 0:
    passed += 1
    sys.stdout.write("passed\n");
else:
    sys.stdout.write("failed\n");


# Run test 3
sys.stdout.write("Running test 3... ")
subprocess.call("./hello_world2",shell=True)
rt = subprocess.call("diff -b 3.out 3.gt",shell=True);
if rt == 0:
    passed += 1
    sys.stdout.write("passed\n");
else:
    sys.stdout.write("failed\n");



sys.stdout.write("\nPassed " + str(passed) + " of 3 tests.\n");
