# otel_with_lttng

This simple C++ project instruments a C++ block of code using [OpenTelemetry C++ SDK](https://opentelemetry-cpp.readthedocs.io/en/latest/sdk/sdk.html) and sends the collected spans to the LTTng consumer daemon using [LTTng-UST](https://lttng.org/docs/v2.13/#doc-c-application) library.

## Run

```bash
docker build --no-cache -t otel_with_lttng . &&  docker run otel_with_lttng:latest
```

Example of program execution output :

```plaintext
root ➜ /workspaces/ciena-opentracing-experiment $ ./run.sh
+ mkdir -p build
+ cd build
+ cmake -G Ninja -D CMAKE_BUILD_TYPE=Release ..
CMake Warning (dev) at /usr/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:438 (message):
  The package name passed to `find_package_handle_standard_args` (Protobuf)
  does not match the name of the calling package (protobuf).  This can lead
  to problems in calling code that expects `find_package` result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  /usr/local/vcpkg/installed/x64-linux/share/protobuf/protobuf-module.cmake:162 (FIND_PACKAGE_HANDLE_STANDARD_ARGS)
  /usr/local/vcpkg/installed/x64-linux/share/protobuf/protobuf-config.cmake:168 (include)
  /usr/local/vcpkg/installed/x64-linux/share/protobuf/vcpkg-cmake-wrapper.cmake:16 (_find_package)
  /usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake:787 (include)
  CMakeLists.txt:20 (find_package)
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Found RE2 via CMake.
-- Configuring done
-- Generating done
-- Build files have been written to: /workspaces/ciena-opentracing-experiment/build
+ ninja
[2/2] Linking CXX executable ciena_opentelemetry_experiment
+ lttng create
Session auto-20221017-201842 created.
Traces will be output to /root/lttng-traces/auto-20221017-201842
+ lttng enable-event -u 'ciena_opentelemetry_experiment:*'
ust event ciena_opentelemetry_experiment:* created in channel channel0
+ lttng add-context -u -t vtid
ust context vtid added to all channels
+ lttng start
Tracing started for session auto-20221017-201842
+ ./ciena_opentelemetry_experiment
Program running ...
Program ended!
+ lttng stop
Waiting for data availability.
Tracing stopped for session auto-20221017-201842
+ lttng view
Trace directory: /root/lttng-traces/auto-20221017-201842

[20:18:42.617564009] (+?.?????????) f53c107505f5 ciena_opentelemetry_experiment:otel_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "\n\x10��eNo��e=�9Ƿ��\x12\b�G�$Y�\x0f2*\x16extensive-task-example0\x019�\x7f\fΩ�\x1e\x17A���ߩ�\x1e\x17" }
[20:18:42.617726265] (+0.000162256) f53c107505f5 ciena_opentelemetry_experiment:otel_debug_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "trace_id: \"\\235\\275eNo\\245\\255e=\\2459\\307\\267\\243\\354\\276\"\nspan_id: \"\\226G\\244$Y\\241\\0172\"\nname: \"extensive-task-example\"\nkind: SPAN_KIND_INTERNAL\nstart_time_unix_nano: 1666037922317238266\nend_time_unix_nano: 1666037922617552292\n" }
[20:18:42.917870310] (+0.300144045) f53c107505f5 ciena_opentelemetry_experiment:otel_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "\n\x10*l�%䷇>\x1c�����\\�\x12\bYF��^��!*\x16extensive-task-example0\x019���ߩ�\x1e\x17A�\x18���\x1e\x17" }
[20:18:42.917919122] (+0.000048812) f53c107505f5 ciena_opentelemetry_experiment:otel_debug_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "trace_id: \"*l\\204%\\344\\267\\207>\\034\\200\\250\\213\\266\\231\\\\\\352\"\nspan_id: \"YF\\214\\345^\\202\\230!\"\nname: \"extensive-task-example\"\nkind: SPAN_KIND_INTERNAL\nstart_time_unix_nano: 1666037922617732349\nend_time_unix_nano: 1666037922917849310\n" }
[20:18:43.218287370] (+0.300368248) f53c107505f5 ciena_opentelemetry_experiment:otel_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "\n\x10\x0emZ�V�d���}�2��\x12\b����\a�*\x16extensive-task-example0\x019\x19����\x1e\x17A#\e�\x03��\x1e\x17" }
[20:18:43.218324437] (+0.000037067) f53c107505f5 ciena_opentelemetry_experiment:otel_debug_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "trace_id: \"\\016mZ\\275V\\227d\\230\\313\\331}\\2672\\341\\226\\332\"\nspan_id: \"\\347\\275\\345\\274\\301\\201\\007\\236\"\nname: \"extensive-task-example\"\nkind: SPAN_KIND_INTERNAL\nstart_time_unix_nano: 1666037922917948441\nend_time_unix_nano: 1666037923218266915\n" }
[20:18:43.518704110] (+0.300379673) f53c107505f5 ciena_opentelemetry_experiment:otel_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "\n\x102\x7f\x10�\x03�\x14{\x06{�{�\x12\bښ���q��*\x16extensive-task-example0\x019\x1cR�\x03��\x1e\x17A2\x1c�\x15��\x1e\x17" }
[20:18:43.518738502] (+0.000034392) f53c107505f5 ciena_opentelemetry_experiment:otel_debug_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "trace_id: \"\\356\\230\\2702\\177\\020\\246\\003\\373\\024{\\006{\\360{\\253\"\nspan_id: \"\\332\\232\\262\\365\\332q\\207\\205\"\nname: \"extensive-task-example\"\nkind: SPAN_KIND_INTERNAL\nstart_time_unix_nano: 1666037923218346524\nend_time_unix_nano: 1666037923518684210\n" }
[20:18:43.819120347] (+0.300381845) f53c107505f5 ciena_opentelemetry_experiment:otel_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "\n\x10R(�߇�v�H�\f�\bB\x1c�\x12\b�\v�(�&o�*\x16extensive-task-example0\x019�I�\x15��\x1e\x17AE\x15�\'��\x1e\x17" }
[20:18:43.819154077] (+0.000033730) f53c107505f5 ciena_opentelemetry_experiment:otel_debug_span: { cpu_id = 2 }, { vtid = 19228 }, { span_stringified_field = "trace_id: \"R(\\274\\337\\207\\204v\\361H\\375\\014\\256\\010B\\034\\262\"\nspan_id: \"\\223\\013\\365(\\257&o\\347\"\nname: \"extensive-task-example\"\nkind: SPAN_KIND_INTERNAL\nstart_time_unix_nano: 1666037923518761409\nend_time_unix_nano: 1666037923819099461\n" }
+ lttng destroy
Destroying session auto-20221017-201842..
Session auto-20221017-201842 destroyed
```
