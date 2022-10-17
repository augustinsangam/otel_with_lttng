#!/usr/bin/env bash

set -ex

# Building the project
mkdir -p build
cd build
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release ..
ninja

# Start a LTTng session and the program
lttng create
lttng enable-event -u 'otel_with_lttng:*'
lttng add-context -u -t vtid
lttng start

./otel_with_lttng

lttng stop
lttng view
lttng destroy
