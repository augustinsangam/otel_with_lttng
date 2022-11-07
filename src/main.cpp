#include <chrono>
#include <iostream>
#include <thread>

#include <opentelemetry/exporters/ostream/span_exporter.h>
#include <opentelemetry/sdk/trace/simple_processor_factory.h>
#include <opentelemetry/sdk/trace/tracer_provider_factory.h>
#include <opentelemetry/trace/provider.h>

#include "lttng_span_exporter.h"

namespace trace = opentelemetry::trace;
namespace trace_sdk = opentelemetry::sdk::trace;

static constexpr int n_traces_to_generate = 2000000;

int main() {
  std::cout << "Program running ..." << std::endl;
  auto exporter = std::unique_ptr<trace_sdk::SpanExporter>(
      new opentelemetry::exporter::trace::LttngSpanExporter);
  auto processor =
      trace_sdk::SimpleSpanProcessorFactory::Create(std::move(exporter));
  std::shared_ptr<opentelemetry::trace::TracerProvider> provider =
      trace_sdk::TracerProviderFactory::Create(std::move(processor));
  // Set the global trace provider
  trace::Provider::SetTracerProvider(provider);
  auto tracer = provider->GetTracer("otel_with_lttng", "0.0.1");

  // Emit n_traces_to_generate spans
  for (int i = 0; i < n_traces_to_generate; i++) {
    // Start a span
    auto span = tracer->StartSpan("extensive-task-example");
    auto scope = tracer->WithActiveSpan(span);
    // Do some work
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // End the span
    span->End();
  }
  std::cout << "Program ended!" << std::endl;

  return 0;
}
