"""specs_s1207.py - fresh slice 12, batch 7 (4 functions). Exe callees hooked by address and logged; the 0x43e8e0 /
0x43e920 hooks log EDX and the stack word only (ECX is a scratch stack buffer whose address differs between builds)."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, hk_cdecl, done


def _s616cc0(c):
    def h(em, r):   # logs the vtable word the destructor has stored by then
        em.calllog.append(('f659c00', 0, em.reg('ecx'), (em.r32(em.reg('ecx') - 0x24),)))
        em.ret(eax=0x659c, argbytes=0)
    c.emu.hook(0x659c00, h)
    c.emu.hook(0x659bb0, hk(0x659bb0, 'f659bb0', 0))
    c.emu.hook(0x634273, hk_cdecl(0x634273, 'delete_sized', 2))


S(0x616cc0, 'FUN_00616cc0 scalar deleting dtor (SEH, size 0x30)', 'thiscall', None, ret='eax', setup=_s616cc0,
  gen=lambda c: done(c, [rand_obj(c, 0x30), c.rng.getrandbits(32)]))


def _fhook(addr, name):
    def h(em, r):
        em.calllog.append((name, 0, 0, (em.reg('edx'), em.arg32(0))))
        em.ret(eax=0x4300 ^ addr, argbytes=4)
    return h


def _g43fa00(c):
    c.emu.hook(0x43e8e0, _fhook(0x43e8e0, 'f43e8e0'))
    c.emu.hook(0x43e920, _fhook(0x43e920, 'f43e920'))
    t = rand_obj(c, 0x50)
    c.emu.wbytes(t + 0x4c, struct.pack('<f', c.rng.choice([0.0, -0.0, 1.0, float('nan'), c.fv()])))
    o = logged_obj(c, 'O', 0x10)
    c.emu.w32(o + 8, t)
    return done(c, [o])


S(0x43fa00, 'FUN_0043fa00 evaluate pair, slot 0, again unless +0x4c == 0', 'thiscall', None, ret=None, gen=_g43fa00)


def _g4f4680(c):
    ok = c.rng.choice([0, 1, 0x100])

    def h(em, r):
        em.calllog.append(('f4f0ce0', 0, em.reg('ecx'), (em.arg32(0), em.r32(em.reg('ecx') + 0x97))))
        em.ret(eax=0xabcd0000 | ok, argbytes=4)
    c.emu.hook(0x4f0ce0, h)
    o = rand_obj(c, 0xb8)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0xac, 0)
    s = logged_obj(c, 'S', 0x20, argwords={0x44: 1, 0x5c: 1})
    return done(c, [o, s])


S(0x4f4680, 'FUN_004f4680 write with temporary +0x97', 'thiscall', None, ret='al', gen=_g4f4680)


def _g57f500(c):
    c.emu.hook(0x562c20, hk(0x562c20, 'f562c20', 1, lambda em: em.arg32(0) * 3))
    c.emu.hook(0x57f750, hk(0x57f750, 'f57f750', 0, lambda em: 0x12345600 | 0x77))
    on = c.rng.choice([0, 1, 0x100])
    a = logged_obj(c, 'A', 0x40, impl={0xb8: lambda e, ar: (0xff00 | on, None)})
    b = logged_obj(c, 'B', 0x40, argwords={0xbc: 1})
    seq = [a, b]
    eng = logged_obj(c, 'Eng', 0x40, impl={0xbc: lambda e, ar: (seq.pop(0), None)})
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10), c.rng.choice([0, 1, 1, 2, c.rng.getrandbits(32)])])


S(0x57f500, 'FUN_0057f500 toggle via engine slot 0xbc or 0x562c20', 'thiscall', None, ret='al', gen=_g57f500)
