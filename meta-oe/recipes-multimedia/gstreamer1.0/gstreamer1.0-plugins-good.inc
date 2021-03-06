require gstreamer1.0-plugins.inc

LICENSE = "GPLv2+ & LGPLv2.1+"

# libid3tag
DEPENDS += "gstreamer1.0-plugins-base zlib bzip2 libcap"

inherit gettext

#cairo gdk-pixbuf gudev v4l2
PACKAGECONFIG ??= " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'pulseaudio', 'pulseaudio', '', d)} \
    orc flac jpeg lame libpng mpg123 soup speex taglib wavpack vpx\
    "

X11DEPENDS = "virtual/libx11 libsm libxrender libxfixes libxdamage"
PACKAGECONFIG[x11]        = "--enable-x,--disable-x,${X11DEPENDS}"
PACKAGECONFIG[pulseaudio] = "--enable-pulse,--disable-pulse,pulseaudio"
PACKAGECONFIG[cairo]      = "--enable-cairo,--disable-cairo,cairo"
PACKAGECONFIG[flac]       = "--enable-flac,--disable-flac,flac"
PACKAGECONFIG[gdk-pixbuf] = "--enable-gdk_pixbuf,--disable-gdk_pixbuf,gdk-pixbuf"
PACKAGECONFIG[gudev]      = "--with-gudev,--without-gudev,libgudev"
PACKAGECONFIG[libv4l2]    = "--with-libv4l2,--without-libv4l2,libv4l2"
PACKAGECONFIG[jack]       = "--enable-jack,--disable-jack,jack"
PACKAGECONFIG[jpeg]       = "--enable-jpeg,--disable-jpeg,jpeg"
PACKAGECONFIG[lame]       = "--enable-lame,--disable-lame,lame"
PACKAGECONFIG[libpng]     = "--enable-libpng,--disable-libpng,libpng"
PACKAGECONFIG[mpg123]     = "--enable-mpg123,--disable-mpg123,mpg123"
PACKAGECONFIG[soup]       = "--enable-soup,--disable-soup,libsoup-2.4"
PACKAGECONFIG[speex]      = "--enable-speex,--disable-speex,speex"
PACKAGECONFIG[taglib]     = "--enable-taglib,--disable-taglib,taglib"
PACKAGECONFIG[twolame]    = "--enable-twolame,--disable-twolame,twolame"
PACKAGECONFIG[vpx]        = "--enable-vpx,--disable-vpx,libvpx"
PACKAGECONFIG[wavpack]    = "--enable-wavpack,--disable-wavpack,wavpack"
PACKAGECONFIG[dv1394]     = "--enable-dv1394,--disable-dv1394,libiec61883 libavc1394 libraw1394"
PACKAGECONFIG[v4l2]       = "--enable-gst_v4l2,--disable-gst_v4l2"


EXTRA_OECONF += " \
    --enable-oss \
    --enable-zlib \
    --enable-bz2 \
    --disable-directsound \
    --disable-waveform \
    --disable-oss4 \
    --disable-osx_audio \
    --disable-osx_video \
    --disable-aalib \
    --disable-aalibtest \
    --disable-libcaca \
    --disable-libdv \
    --disable-shout2 \
    --disable-examples \
"

FILES_${PN}-equalizer += "${datadir}/gstreamer-1.0/presets/*.prs"
