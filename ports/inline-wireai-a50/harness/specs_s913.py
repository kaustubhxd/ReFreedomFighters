"""specs_s913.py - residue-9 slice, batch 913: 0x62de90 (cdecl: object pointer, code; returns a dword; the object's first word and +0xc
are read and written) and 0x610110 (stdcall, one byte flag; calls slot +0xc8 of the object at 0x724a00 with ECX = its vtable and three
words (object, 0x17, n); the stand-in logs them and pops 12). The word at 0x724968 is drawn before each call."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_code(c):
    e, r = c.emu, c.rng
    obj = rnd(c, 0x20)
    e.w32(obj + 0xc, r.choice([0, 1, 0x7]))
    code = r.choice([0xf, 0x1b, 0x1c, 0x1d, 0, r.getrandbits(32)])
    return [obj, code]


def _gen_flag(c):
    e, r = c.emu, c.rng

    def hc8(e, rr):
        e.calllog.append(('P.c8', e.reg('ecx') != 0, e.arg32(0) != 0, e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    P = vt_object(c, 0x40, {0xc8: hc8}, nslots=0x100, name='P')
    e.w32(0x724a00, P)
    e.w32(0x724968, r.choice([0, 4, 8, 3]))
    return [r.choice([0, 1, 0x80, 0xff])]


S(0x62de90, 'code to status (no name in map)', 'cdecl', None, ret='eax', gen=_gen_code, note='area50 batch913 (residue-9 slice)')
S(0x610110, 'flag call (no name in map)', 'stdcall', None, gen=_gen_flag, note='area50 batch913 (residue-9 slice)')
