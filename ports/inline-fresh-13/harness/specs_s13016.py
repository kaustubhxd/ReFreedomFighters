"""specs_s13016.py - fresh-13 batch 16: 0x658950 GUESS ZRender counter-page select. Thiscall (line), ret 4.
PrintCounters 0x650430 (1 arg) is a logged hook returning 0 in 10% of inputs. Slots 0xf8 / 0xf4 are heap code stubs
`fld qword [x]; ret` (double values, so the x87 division precision shows) (x87 st0 result); +0x88 count 1..4 (sometimes 0). Slot 0x118 writes the mouse floats. Mouse
bytes sys+0xa10 / +0xa60 random; sys[+0x190]() returns an object whose slot 0x184 is a logged cdecl stub (4 words,
caller pops). Globals 0x81241c (0/1/2), 0x812420, 0x812424 random. List (this+0x94 slot 0x18) of 0..6 elements, or 0;
iterator slots 0x4c (writes it[0] = 0) and 0x64 (returns element it[0]++ or 0), both logged by tag only. Element
masks (+8+0x1d9) 0 / 1 / 2 / 4 / 8 / shared; this+0x98 random in 0..0x3f; this[+0x1a4]() random bool."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _fstub(c, v):
    x = c.emu.alloc(8, 8)
    c.emu.wbytes(x, struct.pack('<d', v))
    a = c.emu.alloc(16, 16)
    c.emu.wbytes(a, b'\xdd\x05' + struct.pack('<I', x) + b'\xc3' * 10)
    return a


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=48, width=6)
    n88 = r.choice([1, 1, 2, 3, 4, 0])
    hv = r.choice([1.0, 0.5, 2.0, r.uniform(0.2, 3.0)]) * max(n88, 1)
    wv = r.choice([1.0, 0.5, 2.0, r.uniform(0.2, 3.0), 0.0]) * max(n88, 1)
    line = r.randint(0, 4)
    nel = r.choice([0, 1, 2, 3, 4, 6])
    hper = hv / max(n88, 1)
    if r.random() < 0.6:
        my = (line + 1 + r.randint(0, nel) + 0.3) * hper - 0.5
    else:
        my = r.choice([r.uniform(-1, 10), r.randint(0, 10) - 0.5, r.randint(0, 10) + 0.25])
    mx = r.choice([r.uniform(-5, 120), r.uniform(-5, 60), 79.5, 80.5])
    loghook(c, log, 0x650430, 1, 1, ret=(0 if r.random() < 0.1 else r.getrandbits(32) | 1))

    def _mouse(e, rr):
        p = e.r32(e.reg('esp') + 4)
        e.wbytes(p, struct.pack('<2f', mx, my))
        log.put(e, [4, e.reg('ecx')])
        e.ret(eax=0, argbytes=4)
    els = []
    shared = r.choice([1, 2, 4, 8])
    for k in range(nel):
        el = rnd(c, 0x1f0)
        c.emu.w32(el + 8 + 0x1d9, r.choice([0, 0, 0, 1, 2, 4, 8, shared, shared]))
        els.append(el)

    def _init(e, rr):
        e.w32(e.r32(e.reg('esp') + 4), 0)
        log.put(e, [2, e.reg('ecx')])
        e.ret(eax=0, argbytes=4)

    def _next(e, rr):
        p = e.r32(e.reg('esp') + 4)
        i = e.r32(p)
        e.w32(p, i + 1)
        log.put(e, [3, e.reg('ecx'), i])
        e.ret(eax=els[i] if i < len(els) else 0, argbytes=4)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a
    lst = vobj(c, 0x10, {0x4c: _code(_init), 0x64: _code(_next)})
    b1a4 = r.choice([0, 1, 1, 1])
    me = vobj(c, 0xa0, {0xf8: _fstub(c, hv), 0xf4: _fstub(c, wv), 0x118: _code(_mouse),
                        0x1a4: logstub(c, log, 0, 5, ret=b1a4)})
    c.emu.w32(me + 0x88, n88)
    sub = vobj(c, 0x10, {0x18: logstub(c, log, 0, 6, ret=(lst if r.random() < 0.9 else 0))})
    c.emu.wbytes(me + 0x94, bytes(c.emu.mu.mem_read(sub, 4)))
    c.emu.w32(me + 0x98, r.choice([r.randint(0, 0x3f), 0x3f, 0x3f, 0x3f, 0, 1, 3, 7]))
    o = vobj(c, 0x10, {0x184: logstub(c, log, 4, 7, this=False, pop=False)})
    sysobj = vobj(c, 0xa80, {0x190: logstub(c, log, 0, 8, ret=o)})
    c.emu.w8(sysobj + 0xa10, r.choice([0, 0x7f, 0x80, 0xff, 0x80, 0xc0]))
    c.emu.w8(sysobj + 0xa60, r.choice([0, 0x7f, 0x80, 0xff]))
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(0x81241c, r.choice([0, 0, 1, 2]))
    c.emu.w32(0x812420, r.choice([0, 0, 1, 2, 4, 16]))
    c.emu.w8(0x812424, r.choice([0, 1]))
    flush(c)
    return [me, line]


S(0x658950, 'FUN_00658950 (GUESS ZRender counter-page select)', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13016; st0 slots are fld stubs; list iterator, mouse, PrintCounters and cdecl slot logged')
