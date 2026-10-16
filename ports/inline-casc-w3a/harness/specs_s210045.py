"""specs_s210045.py - Sonnet-w3a: chunked list cursor walks; slot 0xc fills the stack cursor, slot 0x10 advances it (Python mirror of the list walk)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _build(c, with38):
    nchunks = c.rng.choice([1, 2, 3])
    chunks = []
    for _ in range(nchunks):
        n = c.rng.choice([1, 1, 2, 3])
        ch = rnd(c, 0x30)
        c.emu.w32(ch, n)
        for i in range(n):
            e = rnd(c, 0x40)
            c.emu.wbytes(e + 5, bytes([c.rng.choice([1, 1, 1, 1, 3, 0])]))
            if with38: c.emu.w32(e + 0x38, c.rng.choice([1, 7, 7, 0]))
            c.emu.w32(ch + 0x10 + 4 * i, e)
        chunks.append(ch)
    for i, ch in enumerate(chunks):
        c.emu.w32(ch + 8, chunks[i + 1] if i + 1 < nchunks else 0)
    return chunks


def _stubs(c, chunks):
    def fill(emu, k):
        p = emu.arg32(0)
        emu.w32(p, chunks[0] + 0x10); emu.w32(p + 4, 0); emu.w32(p + 8, chunks[0])
        emu.calllog.append(('fill', k))

    def advance(emu, k):
        p = emu.arg32(0)
        cur0, idx, chunk = emu.r32(p), emu.r32(p + 4), emu.r32(p + 8)
        idx += 1
        if idx != emu.r32(chunk):
            cur0 += 4
        else:
            chunk = emu.r32(chunk + 8)
            if not chunk:
                cur0 = 0
            else:
                idx = 0
                cur0 = chunk + 0x10
        emu.w32(p, cur0); emu.w32(p + 4, idx); emu.w32(p + 8, chunk)
        emu.calllog.append(('adv', k, cur0, idx, chunk))
    return fill, advance


def _sub_obj(c, chunks):
    fill, advance = _stubs(c, chunks)
    return c.emu.r32(obj(c, 0x40, {0xc: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=fill),
                                   0x10: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=advance)}, nslots=8))


def g6404d0(c):
    clear_hooks(c)
    chunks = _build(c, True)
    t = obj(c, 0x220, {0x80: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    c.emu.w32(t + 0x1f0, _sub_obj(c, chunks))
    return [t]


def g640450(c):
    clear_hooks(c)
    chunks = _build(c, False)
    t = rnd(c, 0x200)
    c.emu.w32(t + 0x1dc, _sub_obj(c, chunks))
    return [t]


S(0x6404d0, 'chunk_list_walk_dispatch', 'thiscall', None, ret=None, gen=g6404d0, note='batch210045')
S(0x640450, 'chunk_list_walk_skip', 'thiscall', None, ret=None, gen=g640450, note='batch210045')
