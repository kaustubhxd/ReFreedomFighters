#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) character skinning: PRM skin + ANM pose -> skinned mesh.

usage: python3 -I skin.py FILE.PRM [--anm FILE.ANM] [--entry 0xOFFSET]
                          [--list] [--clip NAME|--clip-id N] [--tick T] [--loop]
                          [--group N] [--obj OUT.obj] [--png OUT.png] [--check]

  --entry   last PRM entry of a skinned character chain (default: the first
            tag-14 binding of the ANM, i.e. the Hero 0x54a850 in C01A). All
            parts reached through entry +0x08 links are skinned together.
  --list    list skinned chains in the PRM and the clips of the bound group.
  --clip    clip name (or --clip-id) in the ANM source group bound to the
            entry by tag 14 (override with --group); omit for bind pose.
  --tick    local tick inside the clip (float, default 0); --loop wraps it.
  --obj     write the skinned mesh as Wavefront OBJ (coordinates as stored:
            +Y up, character faces -Z).
  --png     write a front + side orthographic render (stdlib PNG).
  --check   numeric checks: rest-global reproduction, weight sums, bind-pose
            skinned == rest mesh, native-palette emulation == closed form.

Everything here is proven from the PC exe unless marked INFERRED; see
skinning-format.md (same folder) for the addresses.  Stdlib only; the game
files are treated as untrusted (every offset is bounds-checked).
"""
import math
import os
import struct
import sys
import zlib


class FormatError(Exception):
    pass


# ----------------------------------------------------------------------------
# small math (column vectors, 3x3 as list of rows)
S = ((0, 0, 1), (0, 1, 0), (1, 0, 0))      # the engine's x<->z storage flip


def mm(a, b):
    return [[sum(a[i][k] * b[k][j] for k in range(3)) for j in range(3)] for i in range(3)]


def mv(a, v):
    return [a[i][0] * v[0] + a[i][1] * v[1] + a[i][2] * v[2] for i in range(3)]


def tr(a):
    return [list(r) for r in zip(*a)]


def qmat(q):
    """Quaternion (x,y,z,w) -> column-vector rotation.  FUN_004df1e0 builds the
    *stored* matrix m = S * R^T of exactly this R (scale 2/|q|^2, so an
    unnormalised quaternion is fine)."""
    x, y, z, w = q
    n = x * x + y * y + z * z + w * w
    s = 2.0 / n if n else 0.0
    return [[1 - s * (y * y + z * z), s * (x * y - w * z), s * (x * z + w * y)],
            [s * (x * y + w * z), 1 - s * (x * x + z * z), s * (y * z - w * x)],
            [s * (x * z - w * y), s * (y * z + w * x), 1 - s * (x * x + y * y)]]


def stored_to_real(m9):
    """Engine 3x3 storage (9 floats row-major) -> column-vector rotation R = m^T S."""
    m = [list(m9[0:3]), list(m9[3:6]), list(m9[6:9])]
    return mm(tr(m), S)


def qmul(a, b):
    """Hamilton product a*b, xyzw storage (FUN_004def50)."""
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return (aw * bx + ax * bw + ay * bz - az * by,
            aw * by + ay * bw + az * bx - ax * bz,
            aw * bz + az * bw + ax * by - ay * bx,
            aw * bw - ax * bx - ay * by - az * bz)


def qblend(a, b, t):
    """FUN_004df040: plain lerp when dot > 0.9, else shortest-arc slerp
    (FUN_004dfb10).  Result is not renormalised (qmat divides by |q|^2)."""
    d = sum(x * y for x, y in zip(a, b))
    if d > 0.9:
        return tuple(x + (y - x) * t for x, y in zip(a, b))
    if sum((y - x) ** 2 for x, y in zip(a, b)) > sum((y + x) ** 2 for x, y in zip(a, b)):
        a = tuple(-x for x in a)
        d = -d
    eps = 1e-6
    if 1 + d > eps:
        if 1 - d > eps:
            om = math.acos(max(-1.0, min(1.0, d)))
            so = math.sin(om)
            sa, sb = math.sin((1 - t) * om) / so, math.sin(t * om) / so
        else:
            sa, sb = 1 - t, t
        return tuple(x * sa + y * sb for x, y in zip(a, b))
    # antiparallel branch of FUN_004dfb10 (xyz-only blend with a helper quat)
    h = (-a[1], a[0], -a[3], a[2])
    sa, sb = math.sin((1 - t) * math.pi / 2), math.sin(t * math.pi / 2)
    return (a[0] * sa + h[0] * sb, a[1] * sa + h[1] * sb, a[2] * sa + h[2] * sb, h[3])


# ----------------------------------------------------------------------------
# PRM
class Prm:
    def __init__(self, path):
        self.d = open(path, 'rb').read()

    def _chk(self, o, n):
        if o < 0 or o + n > len(self.d):
            raise FormatError('PRM read out of bounds at 0x%x' % o)

    def u32(self, o):
        self._chk(o, 4)
        return struct.unpack_from('<I', self.d, o)[0]

    def u16(self, o):
        self._chk(o, 2)
        return struct.unpack_from('<H', self.d, o)[0]

    def f(self, o, n):
        self._chk(o, 4 * n)
        return struct.unpack_from('<%df' % n, self.d, o)

    def is_skinned(self, e):
        try:
            return (self.u32(e) == 0x00010100 and 0 < self.u32(e + 0x7c) <= 128
                    and self.u32(e + 0x98) < 64)
        except FormatError:
            return False

    def scan_skinned(self):
        """All skinned entries (byte scan for the 0x00010100 type word)."""
        out, d, i = [], self.d, 0
        pat = b'\x00\x01\x01\x00'
        while True:
            i = d.find(pat, i)
            if i < 0 or i + 0xa0 > len(d):
                return out
            if self.is_skinned(i) and self.u32(i + 0x88) < len(d):
                vc, vo = self.u16(i + 0xe), self.u32(i + 0x14)
                # vertex (+0x14) and index (+0x3c/+0x40) blocks are separate
                # pointers; the index block is not always right after the
                # vertices (C01A 0x565556, C05A 0x5f17ec/0x610c14)
                if vc and vo + 52 * vc <= len(d) and self.u32(i + 0x3c) + 2 * self.u32(i + 0x40) <= len(d):
                    out.append(i)
            i += 1

    def chain(self, e):
        """Entry +0x08 links to the previous part of the same model (0 = end)."""
        parts, seen = [], set()
        while e and e not in seen:
            if not self.is_skinned(e):
                raise FormatError('entry 0x%x is not a skinned (0x00010100) entry' % e)
            seen.add(e)
            parts.append(e)
            e = self.u32(e + 0x08)
        return parts[::-1]

    def part(self, e):
        """Vertices (52-byte layout), triangles, palette remap of one part."""
        vc = self.u16(e + 0x0e)
        vo, io, iw = self.u32(e + 0x14), self.u32(e + 0x3c), self.u32(e + 0x40)
        # +0x14 vertices and +0x3c index block are independent pointers: the
        # index block is not always stored right after the vertices
        # (C01A 0x565556, C05A 0x5f17ec/0x610c14), so check each on its own.
        self._chk(vo, 52 * vc)
        V = []
        for i in range(vc):
            o = vo + 52 * i
            p = self.f(o, 3)
            w = self.f(o + 12, 3)
            self._chk(o + 24, 4)
            sel = tuple(self.d[o + 24:o + 28])
            n = self.f(o + 28, 3)
            uv = self.f(o + 44, 2)
            V.append((p, w, sel, n, uv))
        # index block: u16 strip count, then {u16 len, len x u16} strips
        self._chk(io, 2 * iw)
        words = struct.unpack_from('<%dH' % iw, self.d, io)
        tris, k = [], 1
        for _ in range(words[0] if words else 0):
            if k >= len(words):
                raise FormatError('entry 0x%x: strip overrun' % e)
            n = words[k]
            s = words[k + 1:k + 1 + n]
            k += 1 + n
            if len(s) != n or any(x >= vc for x in s):
                raise FormatError('entry 0x%x: bad strip' % e)
            for j in range(n - 2):
                a, b, c = s[j], s[j + 1], s[j + 2]
                if a == b or b == c or a == c:
                    continue
                tris.append((b, a, c) if j & 1 else (a, b, c))
        # local palette = concatenated float runs of the bone palette
        # (FUN_00617400 @0x6175ec..0x617649: memcpy(local+acc, pal+start*4, cnt*4))
        remap = []
        for i in range(self.u32(e + 0x98)):
            cnt, start = struct.unpack_from('<II', self.d, self.u32(e + 0x9c) + 8 * i) \
                if self.u32(e + 0x9c) + 8 * i + 8 <= len(self.d) else (None, None)
            if cnt is None or cnt % 12 or start % 12:
                raise FormatError('entry 0x%x: bad palette run' % e)
            remap += list(range(start // 12, start // 12 + cnt // 12))
        return {'entry': e, 'verts': V, 'tris': tris, 'remap': remap}

    def skeleton(self, e):
        n = self.u32(e + 0x7c)
        q84, g88 = self.u32(e + 0x84), self.u32(e + 0x88)
        d90, m94 = self.u32(e + 0x90), self.u32(e + 0x94)
        bones = []
        for i in range(n):
            qt = self.f(q84 + 28 * i, 7)
            g = self.f(g88 + 48 * i, 12)
            self._chk(d90 + 48 * i, 48)
            parent = struct.unpack_from('<i', self.d, d90 + 48 * i + 12)[0]
            name = self.d[d90 + 48 * i + 28:d90 + 48 * i + 44].split(b'\0')[0].decode('latin-1')
            if parent >= i:
                raise FormatError('bone %d parent %d not before it' % (i, parent))
            bones.append({'name': name, 'parent': parent, 'q': qt[:4], 't': qt[4:],
                          'restR': stored_to_real(g[:9]), 'restT': list(g[9:12]),
                          'stored': g})
        self._chk(m94, 96)
        gid2row = {gid: r for gid, r in enumerate(self.d[m94:m94 + 96]) if r != 0xff}
        return {'bones': bones, 'gid2row': gid2row}


# ----------------------------------------------------------------------------
# ANM
class Anm:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        if self.d[:4] != b'MNA\0':
            raise FormatError('not an MNA file')
        self.tags = {}
        self.groups = []
        for h in self._children(0):
            t = self.u32(h)
            if t == 10:
                self.groups.append(h)
            self.tags.setdefault(t, h)
        for t in (4, 5, 6, 7, 8, 11, 13):
            if t not in self.tags:
                raise FormatError('ANM tag %d missing' % t)
        self.pl = {t: self._payload(h) for t, h in self.tags.items()}

    def u32(self, o):
        if o < 0 or o + 4 > len(self.d):
            raise FormatError('ANM read out of bounds at 0x%x' % o)
        return struct.unpack_from('<I', self.d, o)[0]

    def _first(self, h):           # FUN_004e5140
        ln = self.u32(h + 4)
        if not ln & 0x80000000:
            return None
        return h + 0x14 + 4 * self.u32(h + 0x10) if ln & 0x40000000 else h + 0x10

    def _payload(self, h):         # the "& 0xc0000000" test repeated in FUN_004e5a10
        return h + (self.u32(h + 8) if self.u32(h + 4) & 0xc0000000 else 8)

    def _children(self, h):
        end = h + (self.u32(h + 4) & 0x3fffffff)
        c = self._first(h)
        while c is not None and c < end:
            ln = self.u32(c + 4) & 0x3fffffff
            if ln < 8:
                raise FormatError('bad tag length at 0x%x' % c)
            yield c
            c += ln

    def cstr(self, o, lim=64):
        e = self.d.find(b'\0', o, o + lim)
        return self.d[o:e if e >= 0 else o + lim].decode('latin-1')

    def bindings(self):
        """tag 14 rows {groupOrdinal, prmEntry, fit1Based} (FUN_004e5a10)."""
        if 14 not in self.tags:
            return []
        h = self.tags[14]
        n = ((self.u32(h + 4) & 0x3fffffff) - (self.pl[14] - h)) // 12
        return [struct.unpack_from('<3I', self.d, self.pl[14] + 12 * i) for i in range(n)]

    def clips(self, g):
        """Clip records of tag-10 group g (FUN_004e5360 / FUN_004e5160)."""
        h = self.groups[g]
        sub = self._first(h)
        n = self.u32(sub)
        base = sub + (self.u32(sub + 8) if self.u32(sub + 4) & 0xc0000000 else 8)
        out = []
        for i in range(n):
            p = self.pl[5] + self.u32(base + 4 * i)
            out.append({'rec': p, 'name': self.cstr(p, 0x20), 'id': self.u32(p + 0x44),
                        'start': self.u32(p + 0x60), 'end': self.u32(p + 0x64),
                        'tracklist': self.pl[5] + self.u32(p + 0x80)})
        return out

    def group_source(self, g):
        return self.cstr(self._payload(self.groups[g]), 128)

    def tracks(self, clip):
        tl = clip['tracklist']
        out = []
        for i in range(self.u32(tl)):
            t = self.pl[5] + self.u32(tl + 4 + 4 * i)
            j = self.pl[4] + self.u32(t)
            fl = struct.unpack_from('<4H', self.d, t + 4)
            tk = {'joint': self.d[j], 'jname': self.cstr(j + 1, 32), 'sT': fl[0], 'sQ': fl[1],
                  'dur': fl[2], 'flags': fl[3]}
            # dynamic fields: Q (+0x0c data, +0x10 lookup, +0x14 times),
            # then T (+0x18, +0x1c, +0x20); present only when not static.
            if not fl[3] & 0x10:
                tk['q'] = struct.unpack_from('<3I', self.d, t + 0x0c)
            if not fl[3] & 0x08:
                tk['t'] = struct.unpack_from('<3I', self.d, t + 0x18)
            out.append(tk)
        return out

    def look(self, off, idx):
        """FUN_004e5de0: packed MSB-first array in tag 6; index 0 -> 0."""
        if idx == 0:
            return 0
        b = self.pl[6] + off
        w = struct.unpack_from('<b', self.d, b)[0]
        if not 0 < w <= 24:
            raise FormatError('bad packed width %d' % w)
        bit = (idx - 1) * w
        o = b + 1 + (bit >> 3)
        if o + 3 > len(self.d):
            raise FormatError('packed read out of bounds')
        v = (self.d[o] << 16 | self.d[o + 1] << 8 | self.d[o + 2]) << 8
        return (v >> (32 - (bit & 7) - w)) & ((1 << w) - 1)

    def sample(self, tk, time, loop=False):
        """FUN_004e54c0 (vtable 0x6973a4 slot +0x0c): returns (T, Q)."""
        dur = tk['dur']
        time = max(0.0, float(time))
        time = math.fmod(time, dur) if (loop and dur) else min(float(dur), time)
        fi = int(time)
        d = self.d
        if tk['flags'] & 0x08:
            T = struct.unpack_from('<3f', d, self.pl[11] + 12 * tk['sT'])
        elif tk['flags'] & 0x04:
            data, lk, tm = tk['t']
            k = self.look(lk, fi)
            t0 = self.look(tm, k)
            T = struct.unpack_from('<3f', d, self.pl[8] + data + 12 * k)
            if t0 != dur:
                t1 = self.look(tm, k + 1)
                T1 = struct.unpack_from('<3f', d, self.pl[8] + data + 12 * (k + 1))
                u = (time - t0) / (t1 - t0)
                T = tuple(a + (b - a) * u for a, b in zip(T, T1))
        else:
            T = None
        if tk['flags'] & 0x10:
            Q = struct.unpack_from('<4f', d, self.pl[13] + 16 * tk['sQ'])
        else:
            data, lk, tm = tk['q']
            k = self.look(lk, fi)
            t0 = self.look(tm, k)
            if tk['flags'] & 0x01:
                rd = lambda kk: tuple(v / 32512.0 for v in struct.unpack_from('<4h', d, self.pl[7] + data + 8 * kk))
            elif tk['flags'] & 0x02:
                rd = lambda kk: tuple(v / 127.0 for v in struct.unpack_from('<4b', d, self.pl[7] + data + 4 * kk))
            else:
                raise FormatError('track without Q encoding')
            Q = rd(k)
            if t0 != dur:
                t1 = self.look(tm, k + 1)
                Q = qblend(Q, rd(k + 1), (time - t0) / (t1 - t0))
        return T, Q

    def fit(self, fit1, row):
        """tag-15 fitting record (quat xyzw + float3), 28 bytes per PRM bone row."""
        if not fit1 or 15 not in self.pl:
            return None
        o = self.pl[15] + fit1 - 1 + 28 * row
        v = struct.unpack_from('<7f', self.d, o)
        return v[:4], v[4:]


# ----------------------------------------------------------------------------
# pose, palette, skinning
def local_pose(skel, anm=None, clip=None, tick=0.0, loop=False, fit1=0):
    """Per-row local (Q, T).  Rows with a track: sampled (FUN_004e54c0), then
    fitted q = q*fitQ, t += fitT (FUN_00645c90).  Rows without a track keep the
    PRM +0x84 rest local (INFERRED: the per-row state default)."""
    bones = skel['bones']
    loc = [(b['q'], b['t']) for b in bones]
    if clip is None:
        return loc
    for tk in anm.tracks(clip):
        row = skel['gid2row'].get(tk['joint'])
        if row is None:
            continue
        if bones[row]['name'] != tk['jname']:
            raise FormatError('track %s maps to bone %s' % (tk['jname'], bones[row]['name']))
        T, Q = anm.sample(tk, tick, loop)
        if T is None:
            T = bones[row]['t']
        f = anm.fit(fit1, row)
        if f:
            Q = qmul(Q, f[0])
            T = [a + b for a, b in zip(T, f[1])]
        loc[row] = (Q, list(T))
    return loc


def global_pose(skel, loc, root=False):
    """FUN_00659c40 rows 1..n-1:  G = Gp * R(q),  T = Gp * t + Tp.
    Row 0 (GROUND) is not propagated natively (actor/root-motion slot); here it
    is identity unless root=True, which applies the sampled GROUND transform."""
    bones = skel['bones']
    G, T = [], []
    for i, b in enumerate(bones):
        R = qmat(loc[i][0])
        t = list(loc[i][1])
        if b['parent'] < 0:
            if root:
                G.append(R)
                T.append(t)
            else:
                G.append([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
                T.append([0.0, 0.0, 0.0])
        else:
            p = b['parent']
            G.append(mm(G[p], R))
            T.append([a + c for a, c in zip(mv(G[p], t), T[p])])
    return G, T


def palette(skel, G, T):
    """Closed form of FUN_0065be00:  M = G * Rrest^T,  t = T - M * Trest."""
    pal = []
    for b, g, t in zip(skel['bones'], G, T):
        M = mm(g, tr(b['restR']))
        pal.append((M, [a - c for a, c in zip(t, mv(M, b['restT']))]))
    return pal


def palette_native(skel, G, T):
    """Literal emulation of FUN_0065be00 on the engine's stored matrices, for
    --check.  Global slot stored form is m = S*G^T (FUN_004df1e0 convention)."""
    out = []
    for b, g, t in zip(skel['bones'], G, T):
        gs = mm(S, tr(g))                             # animated slot (stored)
        st = b['stored']
        rs = [list(st[0:3]), list(st[3:6]), list(st[6:9])]
        v = st[9:12]
        tmp = [[gs[2 - c][2 - r] for c in range(3)] for r in range(3)]   # FUN_004dfd10
        tmp = mm(mm(tmp, S), rs)                      # FUN_004de480 -> FUN_004419f0 rows
        w = [sum(v[j] * tmp[2 - i][j] for j in range(3)) for i in range(3)]  # FUN_00459fc0
        slot = [tmp[2][0], tmp[2][1], tmp[2][2], t[0] - w[0],
                tmp[1][0], tmp[1][1], tmp[1][2], t[1] - w[1],
                tmp[0][0], tmp[0][1], tmp[0][2], t[2] - w[2]]
        out.append(([slot[0:3], slot[4:7], slot[8:11]], [slot[3], slot[7], slot[11]]))
    return out


def skin_part(part, pal):
    """FUN_00617400: 3 stored weights + derived 4th, palette index = byte/3,
    p' = sum w_i (M_i p + t_i); zero-weight lanes are skipped."""
    lp = [pal[b] for b in part['remap']]
    P, N = [], []
    for p, w, sel, n, uv in part['verts']:
        ws = (w[0], w[1], w[2], 1.0 - w[0] - w[1] - w[2])
        acc, nacc = [0.0, 0.0, 0.0], [0.0, 0.0, 0.0]
        for k in range(4):
            if ws[k] == 0.0:
                continue
            M, t = lp[sel[k] // 3]
            q = mv(M, p)
            r = mv(M, n)
            for j in range(3):
                acc[j] += ws[k] * (q[j] + t[j])
                nacc[j] += ws[k] * r[j]
        P.append(acc)
        N.append(nacc)
    return P, N


# ----------------------------------------------------------------------------
# output
def write_obj(path, parts, posed):
    with open(path, 'w') as f:
        f.write('# Freedom Fighters skinned character, skin.py\n')
        base = 1
        for part, (P, N) in zip(parts, posed):
            f.write('o part_%x\n' % part['entry'])
            for p in P:
                f.write('v %.5f %.5f %.5f\n' % tuple(p))
            for n in N:
                f.write('vn %.5f %.5f %.5f\n' % tuple(n))
            for v in part['verts']:
                f.write('vt %.5f %.5f\n' % (v[4][0], 1 - v[4][1]))
            for a, b, c in part['tris']:
                f.write('f %d/%d/%d %d/%d/%d %d/%d/%d\n' % ((a + base,) * 3 + (b + base,) * 3 + (c + base,) * 3))
            base += len(P)


def png_bytes(w, h, rgb):
    raw = b''.join(b'\0' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))

    def ch(t, d):
        return struct.pack('>I', len(d)) + t + d + struct.pack('>I', zlib.crc32(t + d) & 0xffffffff)
    return (b'\x89PNG\r\n\x1a\n' + ch(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
            + ch(b'IDAT', zlib.compress(raw, 9)) + ch(b'IEND', b''))


PART_COLS = [(200, 170, 140), (120, 150, 200), (150, 200, 130), (210, 140, 160),
             (190, 190, 110), (140, 200, 200), (200, 150, 110)]


def render(views, size=360, joints=None):
    """views: list of (parts, posed, G/T joints or None).  Each view gives two
    panels: front (x, y) and side (z, y), same scale, flat Lambert shading."""
    W, H = size * 2 * len(views), size
    img = bytearray([24, 24, 28] * W * H)
    allp = [p for _, posed, _ in views for P, _ in posed for p in P]
    lo = [min(p[i] for p in allp) for i in range(3)]
    hi = [max(p[i] for p in allp) for i in range(3)]
    ext = max(hi[1] - lo[1], hi[0] - lo[0], hi[2] - lo[2]) * 1.08
    cy = (hi[1] + lo[1]) / 2
    light = (0.4, 0.6, -0.7)
    ln = math.sqrt(sum(x * x for x in light))
    light = [x / ln for x in light]
    for vi, (parts, posed, jt) in enumerate(views):
        for panel in (0, 1):
            ox = (vi * 2 + panel) * size
            cx = (hi[0] + lo[0]) / 2 if panel == 0 else (hi[2] + lo[2]) / 2
            ax = 0 if panel == 0 else 2
            sc = (size - 8) / ext

            def proj(p):
                return (ox + size / 2 + (p[ax] - cx) * sc * (1 if panel else -1),
                        size / 2 - (p[1] - cy) * sc,
                        -p[2] if panel == 0 else p[0])
            zb = [-1e30] * (size * H)
            for pi, (part, (P, N)) in enumerate(zip(parts, posed)):
                col = PART_COLS[pi % len(PART_COLS)]
                Q = [proj(p) for p in P]
                for a, b, c in part['tris']:
                    A, B, C = Q[a], Q[b], Q[c]
                    u = [P[b][i] - P[a][i] for i in range(3)]
                    v = [P[c][i] - P[a][i] for i in range(3)]
                    n = [u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]]
                    nl = math.sqrt(sum(x * x for x in n)) or 1
                    sh = 0.25 + 0.75 * abs(sum(n[i] * light[i] for i in range(3)) / nl)
                    rgb = bytes(min(255, int(x * sh)) for x in col)
                    x0, x1 = max(ox, int(min(A[0], B[0], C[0]))), min(ox + size - 1, int(max(A[0], B[0], C[0])) + 1)
                    y0, y1 = max(0, int(min(A[1], B[1], C[1]))), min(H - 1, int(max(A[1], B[1], C[1])) + 1)
                    den = (B[1] - C[1]) * (A[0] - C[0]) + (C[0] - B[0]) * (A[1] - C[1])
                    if abs(den) < 1e-9:
                        continue
                    for y in range(y0, y1 + 1):
                        for x in range(x0, x1 + 1):
                            l1 = ((B[1] - C[1]) * (x - C[0]) + (C[0] - B[0]) * (y - C[1])) / den
                            l2 = ((C[1] - A[1]) * (x - C[0]) + (A[0] - C[0]) * (y - C[1])) / den
                            l3 = 1 - l1 - l2
                            if l1 < 0 or l2 < 0 or l3 < 0:
                                continue
                            z = l1 * A[2] + l2 * B[2] + l3 * C[2]
                            zi = y * size + (x - ox)
                            if z > zb[zi]:
                                zb[zi] = z
                                o = (y * W + x) * 3
                                img[o:o + 3] = rgb
            if jt:
                G, T, parents = jt
                for i, p in enumerate(parents):
                    if p < 0:
                        continue
                    a, b = proj(T[p]), proj(T[i])
                    steps = int(max(abs(b[0] - a[0]), abs(b[1] - a[1]))) + 1
                    for s in range(steps + 1):
                        x = int(a[0] + (b[0] - a[0]) * s / steps)
                        y = int(a[1] + (b[1] - a[1]) * s / steps)
                        if ox <= x < ox + size and 0 <= y < H:
                            o = (y * W + x) * 3
                            img[o:o + 3] = b'\xff\x30\x30'
    return W, H, img


# ----------------------------------------------------------------------------
def load_character(prm, entry):
    chain = prm.chain(entry)
    skel = prm.skeleton(chain[-1])
    for e in chain:
        for k in (0x7c, 0x80, 0x84, 0x88):
            if prm.u32(e + k) != prm.u32(chain[-1] + k):
                raise FormatError('parts of 0x%x do not share one skeleton' % entry)
    parts = [prm.part(e) for e in chain]
    for p in parts:
        if any(b >= len(skel['bones']) for b in p['remap']):
            raise FormatError('palette run beyond bone count')
    return skel, parts


def pose_character(skel, parts, anm=None, clip=None, tick=0.0, loop=False, fit1=0, root=False):
    loc = local_pose(skel, anm, clip, tick, loop, fit1)
    G, T = global_pose(skel, loc, root)
    pal = palette(skel, G, T)
    return [skin_part(p, pal) for p in parts], (G, T)


def run_checks(prm, anm, entry, skel, parts, clip, fit1):
    ok = True
    # 1. rest local (+0x84) composed == stored rest global (+0x88)
    G, T = global_pose(skel, [(b['q'], b['t']) for b in skel['bones']], root=True)
    e1 = max(max(abs(G[i][r][c] - b['restR'][r][c]) for r in range(3) for c in range(3)) +
             max(abs(T[i][k] - b['restT'][k]) for k in range(3)) for i, b in enumerate(skel['bones']))
    print('rest global from +0x84 vs +0x88: max err %.2e' % e1)
    ok &= e1 < 1e-3
    # 2. weights
    nv = sum(len(p['verts']) for p in parts)
    wneg = sum(1 for p in parts for v in p['verts'] for w in (v[1] + (1 - sum(v[1]),)) if w < -1e-5)
    sel_bad = sum(1 for p in parts for v in p['verts'] for k in range(4) if v[2][k] % 3 or v[2][k] // 3 >= len(p['remap']))
    print('vertices %d: weight sum = 1 by construction (w3 = 1-w0-w1-w2); negative lanes %d; bad selectors %d'
          % (nv, wneg, sel_bad))
    ok &= wneg == 0 and sel_bad == 0
    # 3. bind pose skinned == rest mesh
    posed, _ = pose_character(skel, parts, root=True)
    e3 = max(math.dist(P[i], p['verts'][i][0]) for p, (P, N) in zip(parts, posed) for i in range(len(P)))
    print('bind pose (rest locals): max |skinned - stored| = %.2e units' % e3)
    ok &= e3 < 1e-2
    # 4. native emulation vs closed form, on an animated pose
    if clip is not None:
        loc = local_pose(skel, anm, clip, 5.5, False, fit1)
        G, T = global_pose(skel, loc)
        a, b = palette(skel, G, T), palette_native(skel, G, T)
        e4 = max(abs(x - y) for (M1, t1), (M2, t2) in zip(a, b)
                 for x, y in zip([v for r in M1 for v in r] + t1, [v for r in M2 for v in r] + t2))
        print('palette FUN_0065be00 emulation vs closed form (%s tick 5.5): max err %.2e' % (clip['name'], e4))
        ok &= e4 < 1e-3
        # bone-length preservation
        G, T = global_pose(skel, loc)
        el = max(abs(math.dist(T[i], T[b['parent']]) - math.dist(skel['bones'][i]['restT'], skel['bones'][b['parent']]['restT']))
                 for i, b in enumerate(skel['bones']) if b['parent'] > 0)
        print('bone lengths animated vs rest (excluding GROUND children): max diff %.3f units' % el)
    print('CHECKS', 'PASS' if ok else 'FAIL')
    return ok


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(usage=__doc__.split('\n\n')[1])
    ap.add_argument('prm')
    ap.add_argument('--anm')
    ap.add_argument('--entry')
    ap.add_argument('--list', action='store_true')
    ap.add_argument('--clip')
    ap.add_argument('--clip-id', type=int)
    ap.add_argument('--tick', type=float, default=0.0)
    ap.add_argument('--loop', action='store_true')
    ap.add_argument('--group', type=int)
    ap.add_argument('--root', action='store_true', help='apply sampled GROUND (root motion)')
    ap.add_argument('--obj')
    ap.add_argument('--png')
    ap.add_argument('--check', action='store_true')
    a = ap.parse_args(argv)
    prm = Prm(a.prm)
    anm_path = a.anm or os.path.splitext(a.prm)[0] + '.ANM'
    anm = Anm(anm_path) if os.path.exists(anm_path) else None
    binds = anm.bindings() if anm else []
    entry = int(a.entry, 0) if a.entry else (binds[0][1] if binds else None)
    if a.list:
        ents = prm.scan_skinned()
        lasts = [e for e in ents if not any(prm.u32(x + 8) == e for x in ents)]
        for e in lasts:
            ch = prm.chain(e)
            b = [r for r in binds if r[1] == e]
            print('chain 0x%x parts %s bones %d verts %d tag14 %s' % (
                e, ' '.join('%x' % x for x in ch), prm.u32(e + 0x7c),
                sum(prm.u16(x + 0xe) for x in ch), b))
    if entry is None:
        print('no --entry and no tag-14 binding')
        return 2
    skel, parts = load_character(prm, entry)
    b = [r for r in binds if r[1] == entry]
    group = a.group if a.group is not None else (b[0][0] if b else None)
    fit1 = b[0][2] if (b and (a.group is None or b[0][0] == a.group)) else 0
    clips = anm.clips(group) if (anm and group is not None) else []
    if a.list and clips:
        print('group %d (%s), fit %d:' % (group, anm.group_source(group), fit1))
        for c in clips:
            print('  %3d %-32s ticks %d..%d tracks %d' % (c['id'], c['name'], c['start'], c['end'], anm.u32(c['tracklist'])))
    clip = None
    if a.clip or a.clip_id is not None:
        m = [c for c in clips if c['name'] == a.clip or c['id'] == a.clip_id]
        if not m:
            print('clip not found in group %s' % group)
            return 2
        clip = m[0]
    if a.check:
        run_checks(prm, anm, entry, skel, parts, clip or (clips[0] if clips else None), fit1)
    if a.obj or a.png:
        posed, (G, T) = pose_character(skel, parts, anm, clip, a.tick, a.loop, fit1, a.root)
        if a.obj:
            write_obj(a.obj, parts, posed)
        if a.png:
            W, H, img = render([(parts, posed, (G, T, [x['parent'] for x in skel['bones']]))])
            open(a.png, 'wb').write(png_bytes(W, H, img))
        print('wrote', a.obj or '', a.png or '')
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
