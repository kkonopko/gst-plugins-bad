/* GStreamer MPEG TS Time Shifting
 * Copyright (C) 2011 Fluendo S.A. <support@fluendo.com>
 *               2013 YouView TV Ltd. <william.manley@youview.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __TS_BASE_H__
#define __TS_BASE_H__

#include "tscache.h"

G_BEGIN_DECLS
#define GST_TS_BASE_TYPE \
  (gst_ts_base_get_type())
#define GST_TS_BASE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TS_BASE_TYPE,GstTSBase))
#define GST_TS_BASE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TS_BASE_TYPE,GstTSBaseClass))
#define GST_IS_TS_BASE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TS_BASE_TYPE))
#define GST_IS_TS_BASE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TS_BASE_TYPE))
#define GST_TS_BASE_CAST(obj) \
  ((GstTSBase *)(obj))
#define GST_TS_BASE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),GST_TS_BASE_TYPE,GstTSBaseClass))
typedef struct _GstTSBase GstTSBase;
typedef struct _GstTSBaseClass GstTSBaseClass;

struct _GstTSBase
{
  GstElement element;

  /*< private > */
  GstPad *sinkpad;
  GstPad *srcpad;

  /* Segment */
  GstSegment segment;

  /* flowreturn when srcpad is paused */
  GstFlowReturn srcresult;
  GstFlowReturn sinkresult;
  gboolean is_eos;
  gboolean unexpected;
  gboolean need_newsegment;

  /* the cache of data we're keeping our hands on */
  GstTSCache *cache;
  guint64 cache_size;

  guint cur_bytes;              /* current position in bytes  */

  GMutex flow_lock;            /* lock for flow control */
  GCond buffer_add;            /* signals buffers added to the cache */

  gchar *allocator_name;

  GstEvent *stream_start_event;
};

struct _GstTSBaseClass
{
  GstElementClass parent_class;
};

GType gst_ts_base_get_type (void);

G_END_DECLS
#endif /* __TS_BASE_H__ */
