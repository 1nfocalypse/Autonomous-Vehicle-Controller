#!/bin/bash

echo "=========================="
echo "Starting App okayestcontroller for {APP_PRETTY_NAME}"


systemctl start okayestcontroller
systemctl start rosnodeChecker
