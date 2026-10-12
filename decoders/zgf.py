#!/usr/bin/env python3
"""Freedom Fighters ZGF -> files.

Outer wrapper: u32 rawSize, u32 streamEnd, u8 mode (0 = raw DEFLATE, 1 = stored).
Inside: 'TFGZ', u32 flags, u32 size, u32 count, then `count` records:
  u32 1, u32 0x80000000|recordSize (from this field's start - 4), u32, u32 1,
  u32 dataLen, u32 dataLen+k, data, then the file name as the last
  NUL-terminated string before the record's zero padding.
Contents seen: TrueType fonts (Fonts\\*.TTF) and compiled scripts
(scripts\\<level>\\*.ppo, built from .sdl sources).

usage: zgf.py SCENE.ZGF OUTDIR
"""
import os, re, struct, sys, zlib

def unwrap(d):
    raw, end, mode = struct.unpack_from('<IIB', d)
    body = zlib.decompress(d[9:end], -15) if mode == 0 else d[9:end]
    assert len(body) == raw, 'size mismatch'
    return body

def records(r):
    tag, flags, size, count = struct.unpack_from('<4sIII', r)
    assert tag == b'TFGZ' and size == len(r), 'not TFGZ'
    p = 0x10
    for _ in range(count):
        one, sz = struct.unpack_from('<II', r, p)
        assert one == 1 and sz & 0x80000000, 'bad record at %#x' % p
        sz &= 0x7fffffff
        rec = r[p + 24:p + sz].rstrip(b'\0')
        m = re.search(rb'(?i)(scripts|screens|fonts)\\[^\0]*$', rec)
        cut = m.start() if m else rec.rfind(b'\0') + 1
        name = rec[cut:].decode('latin-1')
        dlen = struct.unpack_from('<I', r, p + 16)[0]
        yield name, r[p + 24:p + 24 + dlen] if name.upper().endswith('.TTF') else rec[:cut].rstrip(b'\0')
        p += sz
    assert p == len(r), 'trailing data'

if __name__ == '__main__':
    src, out = sys.argv[1:3]
    for name, data in records(unwrap(open(src, 'rb').read())):
        rel = os.path.normpath(name.replace('\\', '/')).lstrip('./')
        path = os.path.join(out, rel)
        if os.path.exists(path):
            continue
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, 'wb').write(data)
        print('%8d  %s' % (len(data), name))
