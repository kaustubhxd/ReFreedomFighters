"""specs_s865.py - area 50, batch 865: 0x5a2890 (name GUESS), thiscall with two stack args (a name, a value), ret 8. The
result is void in the port (the exe's zero path returns 0 in eax; not compared, as the checker's bool rule needs a result).
The names are the exe's constants at 0x6ae918 and 0x6ae924 or a random string; stricmp is the CRT import (install_crt_str).
The object's vt +0x5a0 returns a generation-time value, its vt +0x598 is logged; the logger (0x700390) and its sink are fake."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_crt_str


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_crt_str(c)
    tv = r.getrandbits(32)

    def v5a0(e, rr):
        e.calllog.append(('obj.5a0', e.arg32(0)))
        e.ret(eax=tv, argbytes=4)

    def v598(e, rr):
        e.calllog.append(('obj.598', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def l20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    def s2c(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: s2c})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: l20})
    e.w32(0x700390, logger)
    obj = vt_object(c, 0x1000, {0x5a0: v5a0, 0x598: v598}, nslots=0x180, name='obj')
    e.w32(obj + 0x7ae, r.getrandbits(32))
    e.w32(obj + 0x7b2, r.getrandbits(32))
    pick = r.random()
    if pick < 0.35:
        name = 0x6ae918
    elif pick < 0.7:
        name = 0x6ae924
    else:
        name = rnd(c, 16)
        e.wbytes(name, b'zzz_other\x00')
    value = r.choice([0, r.getrandbits(32) | 1])
    return [obj, name, value]


S(0x5a2890, 'Fn5a2890 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch865')
