"""specs_s35200.py - 0x5d00e0 (thiscall, no args, ret=None, nan_heap). this: 0x1000 random bytes with [+0x44] = edi object (slots 0x378 and 0x84, 1 arg each, Python handlers logging and writing the three floats on the caller's stack; unaligned dword +0x676 random; dword +0x684 in 1..5).
Engine: byte +0x6c random (0 / 1), table slots 0x134 (returns O1: slot 0x90, 2 args, writes a flag byte 0 / 1 / 2 through its second argument and logs the name), 0x138 (returns O2: slot 0x88, 2 args, writes a random dword through its second argument and logs the name), 0x58 (1 arg; returns P or 0 in 1/5; P slot 0x80, 2 args).
Logger at 0x700390 (slot 0x20 then slot 0x2c recorded, ECX = the vtable). 0x591ae0 and 0x5922c0 hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5d00e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def h90(em, res_):
        p = em.arg32(1)
        em.calllog.append(('90', em.reg('ecx'), em.arg32(0)))
        em.wbytes(p, bytes([r.choice([0, 1, 2])]))
        em.ret(argbytes=8)

    def h88(em, res_):
        p = em.arg32(1)
        em.calllog.append(('88', em.reg('ecx'), em.arg32(0)))
        em.w32(p, r.getrandbits(32))
        em.ret(argbytes=8)
    O1 = obj(c, 0x20, {0x90: e.stub_fn('90', h90)}, nslots=0x30)
    O2 = obj(c, 0x20, {0x88: e.stub_fn('88', h88)}, nslots=0x30)
    P = obj(c, 0x20, {0x80: pystub(c, 2, this=True)}, nslots=0x30)

    def hv(name, full):
        def h(em, res_):
            v = em.arg32(0)
            em.calllog.append((name, em.reg('ecx')))
            for i in range(3):
                if full or r.random() < 0.5:
                    em.w32(v + 4 * i, _fb(float(r.randint(-500, 500)) + 0.25))
            em.ret(argbytes=4)
        return e.stub_fn(name, h)
    edi = obj(c, 0x700, {0x378: hv('378', True), 0x84: hv('84', False)}, nslots=0xe0)
    e.wbytes(edi + 0x676, r.getrandbits(32).to_bytes(4, 'little'))
    e.w32(edi + 0x684, r.choice([1, 2, 3, 4, 5]))
    me = rnd(c, 0x1000)
    e.w32(me + 0x44, edi)
    so = sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=O1), 0x138: pystub(c, 0, this=True, ret=O2),
                                0x58: pystub(c, 1, this=True, ret=0 if r.random() < 1 / 5 else P)}, table_size=0x140)
    e.w8(so + 0x6c, r.choice([0, 1]))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    hook_rec(c, 0x591ae0, 0, this=True, pop=0, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5922c0, 1, this=True, pop=4)
    return [me]


S(0x5d00e0, 'GUESS initialise vehicle HUD record from owner and engine tables', 'thiscall', None, ret=None, gen=_g5d00e0, nan_heap=True, note='batch35200')
