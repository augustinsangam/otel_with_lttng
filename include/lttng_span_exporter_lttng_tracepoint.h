#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER otel_with_lttng

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./lttng_span_exporter_lttng_tracepoint.h"

#if !defined(_LTTNG_SPAN_EXPORTER_LTTNG_TRACEPOINT_H) ||                       \
    defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _LTTNG_SPAN_EXPORTER_LTTNG_TRACEPOINT_H

#include <lttng/tracepoint.h>

/*
 * Use LTTNG_UST_TRACEPOINT_EVENT(), LTTNG_UST_TRACEPOINT_EVENT_CLASS(),
 * LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(), and
 * LTTNG_UST_TRACEPOINT_LOGLEVEL() here.
 */

LTTNG_UST_TRACEPOINT_EVENT(
    /* Tracepoint provider name */
    otel_with_lttng,
    /* Tracepoint class name */
    otel_span,
    /* Input arguments */
    LTTNG_UST_TP_ARGS(const char *, span_stringified),
    /* Output event fields */
    LTTNG_UST_TP_FIELDS(lttng_ust_field_string(span_stringified_field,
                                               span_stringified)))

LTTNG_UST_TRACEPOINT_EVENT(
    /* Tracepoint provider name */
    otel_with_lttng,
    /* Tracepoint class name */
    otel_debug_span,
    /* Input arguments */
    LTTNG_UST_TP_ARGS(const char *, span_stringified),
    /* Output event fields */
    LTTNG_UST_TP_FIELDS(lttng_ust_field_string(span_stringified_field,
                                               span_stringified)))

#endif /* _LTTNG_SPAN_EXPORTER_LTTNG_TRACEPOINT_H */

#include <lttng/tracepoint-event.h>
