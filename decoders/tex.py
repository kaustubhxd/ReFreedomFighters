#!/usr/bin/env python3
"""Freedom Fighters (PC, Glacier) TEX decoder. Stdlib only. Run with `python3 -I`.

Layout and evidence: decoders/tex-format.md.

  tex.py list     FILE.TEX [--fields]          one line per texture
  tex.py validate FILE.TEX [FILE.TEX ...]      structural check, exit 1 on any error
  tex.py export   FILE.TEX OUTDIR [--id N ...] [--name REGEX] [--base-only]
                                               PNG per texture and per mip
  tex.py anims    FILE.TEX                     animated-texture frame tables (LUT2)
  tex.py sheet    FILE.TEX OUT.png --id N [--id N ...]
                                               contact sheet: each texture with its mip chain

File (all little-endian):
  +0  u32 lut1Off   2048 x u32 record offsets (index == texId, 0 = empty)
  +4  u32 lut2Off   2048 x u32 animation-table offsets (index == texId, 0 = none); file ends here + 8192
  +8  u32 3, +12 u32 4 (constant in all samples; not read by the PC loader)
  +16 content: records, plus animation tables at the offsets LUT2 names
Record (offset o):
  +0  u32 size      whole record incl. this field; next record at o+size
  +4  4cc type      '1TXD' DXT1, '3TXD' DXT3, 'ABGR' RGBA8, 'NLAP' 8-bit palette,
                    'OLAP' palette + opacity map (loader supports it; none in samples)
  +8  4cc type again (ZBitmap::Load checks it against the class)
  +12 u32 texId
  +16 u16 height    +18 u16 width
  +20 u32 mipCount
  +24 u32 flags     0x80 animated (LUT2 table), 0x10 bump/EMBM path, 0x100 seen once (unused by loader)
  +28 u32 materialTypeId  surface type for impacts (ZMaterialDesc::GetTextureTypeId)
  +32 u32 unknown   0 except on NLAP (UI/font) records
  +36 char name[] NUL-terminated
  then mipCount x { u32 size; u8 data[size] }, w,h halved (floor, min 1) per level
  NLAP/OLAP: then u32 palCount; u32 pal[palCount] (bytes R,G,B,A)
  OLAP: then u8 opacity[width*height]
Animation table: u32 count; u32 frameTexId[count] (frame 0 == the owning texId)
"""
import os
import re
import struct
import sys
import zlib

LUT_SLOTS = 2048
FORMATS = {b'1TXD': 'DXT1', b'3TXD': 'DXT3', b'ABGR': 'RGBA8', b'NLAP': 'PAL8', b'OLAP': 'PAL8+OPAC'}
FLAG_BUMP = 0x10
FLAG_ANIMATED = 0x80


class TexError(Exception):
    pass


def mip_bytes(fmt, w, h):
    if fmt == b'1TXD':
        return max(1, (w + 3) // 4) * max(1, (h + 3) // 4) * 8
    if fmt == b'3TXD':
        return max(1, (w + 3) // 4) * max(1, (h + 3) // 4) * 16
    if fmt == b'ABGR':
        return w * h * 4
    if fmt in (b'NLAP', b'OLAP'):
        return w * h
    raise TexError('unknown format %r' % fmt)


class Texture:
    __slots__ = ('off', 'size', 'tag', 'tag2', 'tex_id', 'width', 'height', 'mip_count', 'flags',
                 'material', 'unk32', 'name', 'mips', 'palette', 'opacity', 'end')

    @property
    def fmt(self):
        return FORMATS.get(self.tag, self.tag.decode('latin-1'))


class TexFile:
    def __init__(self, path):
        self.path = path
        with open(path, 'rb') as f:
            self.d = f.read()
        self.errors = []
        self.textures = []
        self.anims = {}          # texId -> [frame texIds]
        self._parse()

    def u32(self, o):
        if o < 0 or o + 4 > len(self.d):
            raise TexError('read out of bounds at 0x%x' % o)
        return struct.unpack_from('<I', self.d, o)[0]

    def err(self, msg):
        self.errors.append(msg)

    def _parse(self):
        d = self.d
        if len(d) < 16:
            raise TexError('file too short')
        self.lut1_off, self.lut2_off, self.hdr8, self.hdr12 = struct.unpack_from('<4I', d, 0)
        if self.lut2_off - self.lut1_off != LUT_SLOTS * 4:
            self.err('lut2Off-lut1Off = %d, expected 8192' % (self.lut2_off - self.lut1_off))
        if self.lut2_off + LUT_SLOTS * 4 != len(d):
            self.err('file size %d != lut2Off+8192 (%d)' % (len(d), self.lut2_off + LUT_SLOTS * 4))
        self.lut1 = struct.unpack_from('<%dI' % LUT_SLOTS, d, self.lut1_off)
        self.lut2 = struct.unpack_from('<%dI' % LUT_SLOTS, d, self.lut2_off)
        anim_offs = {o: i for i, o in enumerate(self.lut2) if o}
        o, end = 16, self.lut1_off
        self.anim_tables_seen = 0
        while o < end:
            if o in anim_offs:
                n = self.u32(o)
                self.anims[anim_offs[o]] = list(struct.unpack_from('<%dI' % n, d, o + 4))
                self.anim_tables_seen += 1
                o += 4 + 4 * n
                continue
            t = self._record(o)
            self.textures.append(t)
            if t.size < 40:
                self.err('record at 0x%x: size %d too small' % (o, t.size))
                break
            o += t.size
        if o != end:
            self.err('content walk ended at 0x%x, LUT1 at 0x%x' % (o, end))
        self.by_off = {t.off: t for t in self.textures}
        self.by_id = {}
        for t in self.textures:
            self.by_id.setdefault(t.tex_id, t)

    def _record(self, o):
        d = self.d
        t = Texture()
        t.off = o
        (t.size, t.tag, t.tag2, t.tex_id, t.height, t.width, t.mip_count, t.flags, t.material,
         t.unk32) = struct.unpack_from('<I4s4sIHHIIII', d, o)
        nul = d.find(b'\0', o + 36, o + t.size)
        if nul < 0:
            raise TexError('record at 0x%x: unterminated name' % o)
        t.name = d[o + 36:nul].decode('latin-1')
        p = nul + 1
        t.mips = []
        w, h = t.width, t.height
        for _ in range(t.mip_count):
            n = self.u32(p)
            t.mips.append((w, h, p + 4, n))
            p += 4 + n
            w, h = max(1, w // 2), max(1, h // 2)
        t.palette = t.opacity = None
        if t.tag in (b'NLAP', b'OLAP'):
            n = self.u32(p)
            t.palette = d[p + 4:p + 4 + 4 * n]
            p += 4 + 4 * n
            if t.tag == b'OLAP':
                t.opacity = d[p:p + t.width * t.height]
                p += t.width * t.height
        t.end = p
        return t

    # ------------------------------------------------------------------ checks
    def validate(self):
        e = self.err
        for t in self.textures:
            where = 'tex %d %r @0x%x' % (t.tex_id, t.name, t.off)
            if t.tag not in FORMATS:
                e('%s: unknown type %r' % (where, t.tag))
                continue
            if t.tag != t.tag2:
                e('%s: type fields differ %r/%r' % (where, t.tag, t.tag2))
            if t.end != t.off + t.size:
                e('%s: payload ends at 0x%x, record ends at 0x%x' % (where, t.end, t.off + t.size))
            ser = 0x1d + len(t.name.encode('latin-1')) + sum(4 + m[3] for m in t.mips)
            if t.palette is not None:
                ser += 4 + len(t.palette)
            if t.opacity is not None:
                ser += len(t.opacity)
            if ser + 8 != t.size:
                e('%s: size %d != 8 + serialized size %d' % (where, t.size, ser))
            full = max(t.width, t.height).bit_length()
            if not 1 <= t.mip_count <= full:
                e('%s: mipCount %d outside 1..%d' % (where, t.mip_count, full))
            for i, (w, h, p, n) in enumerate(t.mips):
                if n != mip_bytes(t.tag, w, h):
                    e('%s: mip %d %dx%d has %d bytes, expected %d' % (where, i, w, h, n, mip_bytes(t.tag, w, h)))
            if t.palette is not None:
                npal = len(t.palette) // 4
                for i, (w, h, p, n) in enumerate(t.mips):
                    if n and max(self.d[p:p + n]) >= npal:
                        e('%s: mip %d index >= palCount %d' % (where, i, npal))
            if t.tex_id >= LUT_SLOTS:
                e('%s: texId >= 2048' % where)
            elif self.lut1[t.tex_id] != t.off:
                e('%s: LUT1[texId] = 0x%x' % (where, self.lut1[t.tex_id]))
            anim = t.tex_id < LUT_SLOTS and self.lut2[t.tex_id] != 0
            if bool(t.flags & FLAG_ANIMATED) != anim:
                e('%s: flag 0x80=%d but LUT2 entry %s' % (where, bool(t.flags & FLAG_ANIMATED), anim))
        for i, o in enumerate(self.lut1):
            if o and (o not in self.by_off or self.by_off[o].tex_id != i):
                e('LUT1[%d] = 0x%x is not the record of texId %d' % (i, o, i))
        nref = sum(1 for o in self.lut1 if o)
        if nref != len(self.textures):
            e('LUT1 has %d entries, %d records' % (nref, len(self.textures)))
        if self.anim_tables_seen != sum(1 for o in self.lut2 if o):
            e('LUT2 has %d entries, %d tables met in the walk' % (sum(1 for o in self.lut2 if o), self.anim_tables_seen))
        for tid, frames in self.anims.items():
            if not frames or frames[0] != tid:
                e('anim table of %d does not start with itself: %s' % (tid, frames[:4]))
            for f in frames:
                if f not in self.by_id:
                    e('anim table of %d names missing texId %d' % (tid, f))
        return self.errors

    # ------------------------------------------------------------------ decode
    def decode_mip(self, t, level=0):
        """Return (w, h, rgba bytes) for one mip level."""
        w, h, p, n = t.mips[level]
        src = self.d[p:p + n]
        if t.tag == b'ABGR':
            return w, h, bytes(src)          # bytes are R,G,B,A (ZBitmap32 masks R=0xff .. A=0xff000000)
        if t.tag in (b'NLAP', b'OLAP'):
            pal = t.palette
            out = bytearray(w * h * 4)
            for i, ix in enumerate(src):
                out[4 * i:4 * i + 4] = pal[4 * ix:4 * ix + 4]
            if t.opacity is not None and level == 0:
                for i in range(w * h):
                    out[4 * i + 3] = t.opacity[i]
            return w, h, bytes(out)
        return w, h, decode_dxt(src, w, h, t.tag == b'3TXD')


def _565(c):
    r, g, b = (c >> 11) & 31, (c >> 5) & 63, c & 31
    return ((r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2))


def decode_dxt(src, w, h, dxt3):
    bw, bh = max(1, (w + 3) // 4), max(1, (h + 3) // 4)
    out = bytearray(w * h * 4)
    bsz = 16 if dxt3 else 8
    o = 0
    for by in range(bh):
        for bx in range(bw):
            if dxt3:
                alpha = int.from_bytes(src[o:o + 8], 'little')
                c0, c1, bits = struct.unpack_from('<HHI', src, o + 8)
            else:
                alpha = None
                c0, c1, bits = struct.unpack_from('<HHI', src, o)
            o += bsz
            a, b = _565(c0), _565(c1)
            if c0 > c1 or dxt3:
                pal = (a + (255,), b + (255,),
                       tuple((2 * x + y) // 3 for x, y in zip(a, b)) + (255,),
                       tuple((x + 2 * y) // 3 for x, y in zip(a, b)) + (255,))
            else:   # DXT1 3-colour mode: index 3 is transparent black
                pal = (a + (255,), b + (255,), tuple((x + y) // 2 for x, y in zip(a, b)) + (255,), (0, 0, 0, 0))
            for py in range(4):
                y = by * 4 + py
                if y >= h:
                    break
                row = y * w
                for px in range(4):
                    x = bx * 4 + px
                    if x >= w:
                        continue
                    k = py * 4 + px
                    c = pal[(bits >> (2 * k)) & 3]
                    q = 4 * (row + x)
                    out[q:q + 3] = bytes(c[:3])
                    out[q + 3] = ((alpha >> (4 * k)) & 15) * 17 if dxt3 else c[3]
    return bytes(out)


def write_png(path, w, h, rgba):
    raw = b''.join(b'\0' + rgba[y * w * 4:(y + 1) * w * 4] for y in range(h))

    def chunk(t, b):
        return struct.pack('>I', len(b)) + t + b + struct.pack('>I', zlib.crc32(t + b) & 0xffffffff)
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0))
                + chunk(b'IDAT', zlib.compress(raw, 6)) + chunk(b'IEND', b''))


def safe_name(s):
    return re.sub(r'[^A-Za-z0-9_.#-]+', '_', s)[:80]


# ---------------------------------------------------------------------- CLI
def cmd_list(tf, fields):
    print('# %s  textures=%d  animTables=%d  hdr8=%d hdr12=%d' % (
        os.path.basename(tf.path), len(tf.textures), len(tf.anims), tf.hdr8, tf.hdr12))
    print('# texId fmt       WxH       mips flags  mat  name' + ('  [off size unk32 pal]' if fields else ''))
    for t in tf.textures:
        line = '%5d %-9s %4dx%-4d  %2d  0x%03x %4d  %s' % (
            t.tex_id, t.fmt, t.width, t.height, t.mip_count, t.flags, t.material, t.name)
        if fields:
            line += '  [0x%x %d 0x%08x %s]' % (t.off, t.size, t.unk32,
                                              len(t.palette) // 4 if t.palette is not None else '-')
        print(line)


def summarize(tf):
    from collections import Counter
    fm = Counter(t.fmt for t in tf.textures)
    nm = sum(t.mip_count for t in tf.textures)
    full = sum(1 for t in tf.textures if t.mip_count == max(t.width, t.height).bit_length())
    one = sum(1 for t in tf.textures if t.mip_count == 1)
    mipbytes = sum(m[3] for t in tf.textures for m in t.mips)
    return ('records=%d mips=%d (full chain %d, single level %d, partial %d) mipBytes=%d formats=%s '
            'animTables=%d flags=%s' % (len(tf.textures), nm, full, one, len(tf.textures) - full - one, mipbytes,
                                        dict(fm), len(tf.anims),
                                        dict(Counter(hex(t.flags) for t in tf.textures))))


def cmd_validate(paths):
    bad = 0
    for p in paths:
        try:
            tf = TexFile(p)
            errs = tf.validate()
        except (TexError, struct.error) as ex:
            print('FAIL %s: %s' % (p, ex))
            bad += 1
            continue
        print('%s %s: %s' % ('OK  ' if not errs else 'FAIL', os.path.basename(p), summarize(tf)))
        for m in errs[:30]:
            print('   ', m)
        bad += bool(errs)
    return 1 if bad else 0


def select(tf, ids, name_re):
    out = tf.textures
    if ids:
        out = [t for t in out if t.tex_id in ids]
    if name_re:
        r = re.compile(name_re)
        out = [t for t in out if r.search(t.name)]
    return out


def cmd_export(tf, outdir, ids, name_re, base_only):
    os.makedirs(outdir, exist_ok=True)
    n = 0
    for t in select(tf, ids, name_re):
        for lvl in range(1 if base_only else t.mip_count):
            w, h, px = tf.decode_mip(t, lvl)
            write_png(os.path.join(outdir, '%04d_%s_m%d_%dx%d.png' % (t.tex_id, safe_name(t.name), lvl, w, h)),
                      w, h, px)
            n += 1
    print('wrote %d PNGs to %s' % (n, outdir))


def cmd_anims(tf):
    for tid, frames in sorted(tf.anims.items()):
        print('%d %s: %d frames %s' % (tid, tf.by_id[tid].name if tid in tf.by_id else '?', len(frames), frames))


def cmd_sheet(tf, out, ids):
    """Each row: base level then every mip, left to right, on a checkerboard so alpha shows."""
    rows = []
    for tid in ids:
        t = tf.by_id.get(tid)
        if t is None:
            raise TexError('no texId %d' % tid)
        rows.append([tf.decode_mip(t, i) for i in range(t.mip_count)])
    pad = 4
    W = max(sum(m[0] + pad for m in r) + pad for r in rows)
    H = sum(max(m[1] for m in r) + pad for r in rows) + pad
    img = bytearray(W * H * 4)
    for y in range(H):
        for x in range(W):
            v = 200 if ((x >> 3) ^ (y >> 3)) & 1 else 150
            img[4 * (y * W + x):4 * (y * W + x) + 4] = bytes((v, v, v, 255))
    y0 = pad
    for r in rows:
        x0 = pad
        for (w, h, px) in r:
            for y in range(h):
                for x in range(w):
                    s = 4 * (y * w + x)
                    a = px[s + 3]
                    q = 4 * ((y0 + y) * W + x0 + x)
                    for c in range(3):
                        img[q + c] = (px[s + c] * a + img[q + c] * (255 - a)) // 255
            x0 += w + pad
        y0 += max(m[1] for m in r) + pad
    write_png(out, W, H, bytes(img))
    print('wrote %s (%dx%d, %d textures)' % (out, W, H, len(rows)))


def main(argv):
    if len(argv) < 2 or argv[0] not in ('list', 'validate', 'export', 'anims', 'sheet'):
        print(__doc__)
        return 2
    cmd, args = argv[0], argv[1:]
    ids = [int(args[i + 1]) for i, a in enumerate(args) if a == '--id']
    name_re = next((args[i + 1] for i, a in enumerate(args) if a == '--name'), None)
    pos = [a for i, a in enumerate(args) if not a.startswith('--') and (i == 0 or args[i - 1] not in ('--id', '--name'))]
    if cmd == 'validate':
        return cmd_validate(pos)
    tf = TexFile(pos[0])
    if cmd == 'list':
        cmd_list(tf, '--fields' in args)
    elif cmd == 'export':
        cmd_export(tf, pos[1], ids, name_re, '--base-only' in args)
    elif cmd == 'anims':
        cmd_anims(tf)
    elif cmd == 'sheet':
        cmd_sheet(tf, pos[1], ids)
    return 0


if __name__ == '__main__':
    try:
        sys.exit(main(sys.argv[1:]))
    except BrokenPipeError:
        sys.exit(0)
