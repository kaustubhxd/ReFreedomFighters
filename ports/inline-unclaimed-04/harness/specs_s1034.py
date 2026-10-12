"""specs_s1034.py - unclaimed-04 batch 34 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
0x64b070 (thiscall, plain ret): when the byte at +0x10028 is set, calls 0x64dd20 (hooked by address), then obj(+0x1005d)
->vt[0x24](ptr(+0x10071), 0x4000) (recording stub), clears +0x10071 and the byte at +0x10028.
0x605570 (cdecl plain ret, returns 0): the logger of batch 33 with other constants; the callback global 0x7003b0 is always a
non-zero stub (null reaches an int3 assert). The object for 0x64b070 is a zeroed 0x10100-byte block."""
from pilot import S


def _setup_b070(c):
    def h64dd20(em, r):
        em.calllog.append(('64dd20', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x64dd20, h64dd20)


def _args_b070(c):
    o = c.emu.alloc(0x10100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x10100)))
    c.emu.wbytes(o + 0x10028, bytes([c.rng.choice([0, 1, 1])]))
    obj_vt = c.emu.fake_vtable('b070 obj', 0x24 // 4 + 1, {0x24: lambda em, r: (
        em.calllog.append(('obj.24', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8))})
    obj = c.emu.alloc(0x40, 4)
    c.emu.w32(obj, obj_vt)
    c.emu.w32(o + 0x1005d, obj)
    c.emu.w32(o + 0x10071, c.rng.getrandbits(32))
    return [o]


def _setup_logger(c):
    def h_20(em, r):
        em.calllog.append(('obj.20', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=L, argbytes=8)

    def h_2c(em, r):
        em.calllog.append(('L.2c', 0, 0, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)

    L_vt = c.emu.fake_vtable('logger L', 0x2c // 4 + 1, {0x2c: h_2c})
    L = c.emu.alloc(0x40, 4)
    c.emu.w32(L, L_vt)
    obj_vt = c.emu.fake_vtable('logger obj', 0x20 // 4 + 1, {0x20: h_20})
    obj = c.emu.alloc(0x100, 4)
    c.emu.w32(obj, obj_vt)
    c.emu.w32(0x700390, obj)

    def h_cb(em, r):
        em.calllog.append(('7003b0', 0, 0, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.w32(0x7003b0, c.emu.stub_fn('cb7003b0', h_cb))


def _none(c):
    return []


S(0x64b070, 'unknown::clear_when_flag_vt24 (unknown) thiscall', 'thiscall', None, ret=None, gen=_args_b070,
  setup=_setup_b070, note='unclaimed-04 batch 34; 0x64dd20 hooked (GUESS); obj slot 0x24 recording stub')
S(0x605570, 'unknown::logger_b (unknown) cdecl', 'cdecl', None, ret='eax', gen=_none,
  setup=_setup_logger, note='unclaimed-04 batch 34; logger global 0x700390 non-zero, callback stubbed (area 70 model)')
