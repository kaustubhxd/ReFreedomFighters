"""specs_s605.py - area 49 batch 605: CEnemyFlag::ReadInput(DBREAD &) (0x5c1dc0).
Callees hooked by address (same for the port and the original): 0x4e5ea0 (name read, returns a heap string whose length
crosses the 10-character boundary), 0x4e5e60 (DBREAD u32 operator, via serial_stubs.dbread_patch), 0x4dc110 (node name),
0x4cc850 (wildcard match, fastcall). The CRT strncpy is the import at 0x67642c (stub_import: copies up to n bytes, stops
at NUL, zero-pads). The object, render manager (global 0x70039c), logger (global 0x700390) and stream use serial_stubs.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
from wkit import rnd  # noqa: E402
import serial_stubs as ss  # noqa: E402

P = ss.P
RM_GLOBAL = 0x70039c
LOG_GLOBAL = 0x700390


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _setup(c):
    r = c.rng
    # the name: lengths 0..14 so both the debug-log branch (> 10) and the copy branch are exercised
    n = r.randint(0, 14)
    name = bytes(r.randint(0x41, 0x5a) for _ in range(n))
    name_ptr = _cstr(c, name)
    c.emu.hook(0x4e5ea0, lambda e, rr: e.ret(eax=name_ptr, argbytes=0))

    node_name = _cstr(c, bytes(r.randint(0x41, 0x5a) for _ in range(r.randint(0, 9))))
    c.emu.hook(0x4dc110, lambda e, rr: e.ret(eax=node_name, argbytes=0))
    m4cc = [r.choice((0, 0, 1, 2)) for _ in range(64)]   # wildcard results, consumed in call order
    mi = {'i': 0}

    def h4cc(e, rr):
        e.ret(eax=m4cc[mi['i'] % len(m4cc)], argbytes=0)
        mi['i'] += 1
    c.emu.hook(0x4cc850, h4cc)

    # DBREAD::operator unsigned int: first read is the value stored twice; the fourth read is the flag
    ss.dbread_patch(c, [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice((0, 1, 7))],
                    [0], [0])

    def strncpy(e, rr):
        dst, src, cnt = e.arg32(0), e.arg32(1), e.arg32(2)
        data = bytearray(e.rbytes(src, cnt))
        out = bytearray(cnt)
        for i in range(cnt):
            if data[i] == 0:
                break
            out[i] = data[i]
        e.wbytes(dst, bytes(out))
        e.ret(eax=dst, argbytes=0)
    c.emu.stub_import('strncpy', strncpy)

    # the by-name get (slot 0x25c) answers from a table fixed for the run, so the original and the port see the same
    # values. The name 0x6b3ba8 answers an object with slot 0x84 (the port calls it) or 0.
    t84 = ss.mkobj(c, {0x84: ss.rec(c, 1)})
    vals = {0x6b3b58: r.choice((0, r.getrandbits(32) | 1)), 0x6b3b68: 0,
            0x6b3b78: r.choice((0, r.getrandbits(32) | 1)), 0x6b3b90: r.choice((0, r.getrandbits(32) | 1)),
            0x6b3ba8: r.choice((0, t84))}

    def get_h(e, rr):
        name, dflt = e.arg32(0), e.arg32(1)
        e.calllog.append(('dbr.get', 0x25c, e.reg('ecx'), (name, dflt)))
        e.ret(eax=vals.get(name, dflt) or dflt, argbytes=8)
    obj2 = c.emu.fake_object('dbr2', 0x40, nslots=0x260, slots={0x25c: get_h})

    def slot20(e, rr):
        e.calllog.append(('dbr.obj', 0x20, e.reg('ecx'), ()))
        e.ret(eax=obj2, argbytes=0)
    o = c.emu.fake_object('dbr', 0x60, nslots=0x260, slots={0x20: slot20, 0x25c: get_h})
    q = c.emu.alloc(0x40, 16)
    c.emu.w32(q + 0x23, r.getrandbits(32))
    c.emu.w32(o + 0xc, q)
    # a short node list (0..3 nodes): node +0x54 value, +0x60 next
    nodes = []
    for _ in range(r.randint(0, 3)):
        nd = c.emu.alloc(0x64, 16)
        c.emu.w32(nd + 0x54, r.getrandbits(32))
        c.emu.w32(nd + 0x60, 0)
        nodes.append(nd)
    for a, b in zip(nodes, nodes[1:]):
        c.emu.w32(a + 0x60, b)
    c.emu.w32(o + 0x50, nodes[0] if nodes else 0)
    c.emu.w32(obj2 + 0x50, 0)

    # render manager at [RM_GLOBAL]+0x9b with slot 0x4c returning a fixed sequence
    rm = ss.mkobj(c, {0x4c: ss.seqr(c, 1, [r.getrandbits(32) | 1, r.getrandbits(32) | 1, r.getrandbits(32) | 1])})
    sysv = c.emu.alloc(0xa0, 16)
    c.emu.wbytes(sysv, bytes(r.getrandbits(8) for _ in range(0xa0)))
    c.emu.w32(sysv + 0x9b, rm)
    c.emu.w32(RM_GLOBAL, sysv)
    c.emu._image_dirty = True

    # logger at [LOG_GLOBAL]: slot 0x20 (file, line) returns the stream; the stream's slot 0x2c is cdecl (stream, fmt, s)
    def printf_h(e, rr):
        e.calllog.append(('log.printf', 0x2c, 0, (e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=0)
    stream = c.emu.fake_object('stream', 0x40, nslots=0x30, slots={0x2c: printf_h})

    def log_h(e, rr):
        e.calllog.append(('log.get', 0x20, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=stream, argbytes=8)
    lg = c.emu.fake_object('logger', 0x40, nslots=0x30, slots={0x20: log_h})
    c.emu.w32(LOG_GLOBAL, lg)

    # slot 0x84 on the fallback object (this+0x30 when slot 0x25c returns 0) and on the returned object
    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(self_ + 0x44, o)
    c.emu.w32(self_ + 0x30, t84)
    dbr = rnd(c, 0x20)
    return self_, dbr


def _gen(c):
    self_, dbr = _setup(c)
    return [self_, dbr]


S(0x5c1dc0, 'CEnemyFlag::ReadInput', 'thiscall', None, ret=None, gen=_gen)
