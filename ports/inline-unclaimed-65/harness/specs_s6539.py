"""specs_s6539.py - unclaimed-65 batch 39 (docs/20-unclaimed-65.md, claim 21), group 5: ZInputActions::GetButtonName (stdcall, ret 8) with
the high word 0 and a bank table: the search runs over the bank records (ids at 0x6e48bc + 16k, counts at 0x6e48c4 + 16k, bases at
0x6e48c0 + 16k, the list ends at an id of 0). The index is below the total count (so a bank is found, with edx = its index k, 0 to 6,
including case 0 for k = 0, cases 1 to 5, and the default for k = 6) or above it (edx = 0, the remaining index is used in case 0). Case 0 goes through the
0x6e4928 pairs (empty here) and the render fake. The real helpers run. The cookie check runs as the real code. Globals are set in gen."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 4)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _setup(c):
    _flush_code(c)


def _gen(c):
    nb = c.rng.randint(1, 7)                          # up to seven banks: a found bank 6 gives the edx > 5 default
    counts = [c.rng.randint(1, 8) for _ in range(nb)]
    total = sum(counts)
    bases = []
    for b in range(nb):
        blk = _rnd(c, 12 * 16)
        for k in range(16):
            c.emu.w32(blk + 12 * k + 4, c.rng.choice([0xb8, 0x10, 0x27, c.rng.getrandbits(32)]))
            c.emu.w32(blk + 12 * k + 8, _cstr(c, b'Bank%dEntry%d' % (b, k)))
        bases.append(blk)
        c.emu.w32(0x6e48bc + 16 * b, b + 1)            # a non-zero bank id (the search compares against 0 only, see the port)
        c.emu.w32(0x6e48c4 + 16 * b, counts[b])
        c.emu.w32(0x6e48c0 + 16 * b, blk)
    c.emu.w32(0x6e48bc + 16 * nb, 0)                  # the list ends
    c.emu.w32(0x6e4928, 0)
    def s_dc(e, r):
        e.calllog.append(('0xdc', e.reg('ecx'), (e.arg32(1),)))
        e.w32(e.arg32(0), (e.arg32(0) + 4) & 0xffffffff)
        e.wbytes(e.arg32(0) + 4, b'A\x00')
        e.ret(eax=0, argbytes=8)

    def s198(e, r):
        e.calllog.append(('0x198', (e.arg32(0), e.arg32(2), e.arg32(3))))
        o_ = e.reg('ecx')
        e.w32(o_, (o_ + 4) & 0xffffffff)
        e.wbytes(o_ + 4, b'Z\x00')
        e.ret(eax=0, argbytes=0)

    def s_o0(e, r):
        a = e.r32(e.arg32(1))
        txt = b''
        while len(txt) < 0x40 and e.rbytes(a + len(txt), 1) != b'\x00':
            txt += e.rbytes(a + len(txt), 1)
        e.calllog.append(('0xo0', e.reg('ecx'), (e.arg32(0), txt)))
        e.ret(eax=tail_s, argbytes=8)

    # case 1 (a bank with id 2 found): slot 0x190 of the render object gives P; P's slot 0x198 is caller-cleaned; the object o
    # (at [render + 0x9b] + 0xae4) returns the string for out
    tail_s = _cstr(c, b'Tail')
    p_vt = c.emu.fake_vtable('gbn-p5', 0x300, {0x198: s198})
    p = _rnd(c, 0x40)
    c.emu.w32(p, p_vt)
    o_vt = c.emu.fake_vtable('gbn-o5', 0x40, {0x0: s_o0})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    r9b = _rnd(c, 0x1000)
    c.emu.w32(r9b + 0xae4, o)
    rend_vt = c.emu.fake_vtable('gbn-rend5', 0x300, {
        0xdc: s_dc,
        0x190: lambda e, r: (e.calllog.append(('0x190', e.reg('ecx'), ())), e.ret(eax=p, argbytes=0))})
    rend = _rnd(c, 0x200)
    c.emu.w32(rend, rend_vt)
    c.emu.w32(rend + 0x9b, r9b)
    c.emu.wbytes(rend + 0x6e, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(0x70039c, rend)
    out = _rnd(c, 0x80)
    idx = c.rng.randint(0, total + 3)
    return [out, idx]


S(0x439020, 'ZInputActions::GetButtonName (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 39 (claim 21); group 5: the bank search (found or not found)')
