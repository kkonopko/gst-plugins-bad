plugin_LTLIBRARIES = libgstflutimeshift.la

# sources used to compile this plugin
libgstflutimeshift_la_SOURCES = \
  gsttsindexer.c \
  gsttsseeker.c \
  gsttsshifter.c \
  gsttsshifterbin.c \
  gsttstimeshift.c \
  tsbase.c \
  tscache.c \
  tsindex.c \
  tsmemindex.c

libgstflutimeshift_la_CFLAGS = \
 -I$(top_srcdir)/common \
  $(GST_CFLAGS) \
  $(GST_BASE_CFLAGS) \
  $(GST_PLUGINS_BASE_CFLAGS) \
  $(CPU_TUNE_CFLAGS)

libgstflutimeshift_la_LDFLAGS = \
  $(GST_PLUGIN_LDFLAGS) \
  $(CPU_TUNE_LDFLAGS)

libgstflutimeshift_la_LIBADD = \
  $(GST_LIBS) \
  $(GST_BASE_LIBS) \
  $(GST_PLUGINS_BASE_LIBS)

# headers we need but don't want installed
noinst_HEADERS = \
  gsttsindexer.h \
  gsttsseeker.h \
  gsttsshifter.h \
  gsttsshifterbin.h \
  tsbase.h \
  tscache.h \
  tsindex.h
