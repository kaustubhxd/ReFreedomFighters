"""specs_s900.py - gap-band slice, batch 900: 0x41ede0 (ZSysMem::IsMallocSimple, thiscall, one stack arg (name), ret 4, returns a
dword) and 0x420170 (ZSysInterfaceGC::GetCharacter, thiscall, one stack arg (index), ret 4, returns bool).
Stand-ins: 0x4d12e0 (thiscall, ECX = the table entry, one argument, ret 4, returns al; each entry's answer is drawn at generation
time) and the object's slot +0x1f8 (one argument, returns al; drawn). The engine float +0x9c7 is drawn equal, above, or NaN against
the constant at 0x6785d0; the flag byte at this+5*idx+0xa0b is drawn with bits 1 and 7 random."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_malloc(c):
    e, r = c.emu, c.rng
    answers = {}

    def h_4d12(e, rr):
        obj = e.reg('ecx')
        e.calllog.append(('h.4d12e0', answers.get(obj, 0), e.arg32(0) != 0))
        e.ret(eax=1 if answers.get(obj, 0) else 0, argbytes=4)

    only_hooks(c, {0x4d12e0: h_4d12})
    self = rnd(c, 0x100)
    n = r.randint(0, 4)
    e.w32(self + 0x45, n)
    for i in range(n):
        if r.random() < 0.25:
            e.w32(self + 0x35 + 4 * i, 0)
        else:
            o = rnd(c, 0x20)
            answers[o] = r.random() < 0.3
            e.w32(self + 0x35 + 4 * i, o)
    return [self, e.cstr('ZSysMem')]


def _gen_char(c):
    e, r = c.emu, c.rng
    ans = [1 if r.random() < 0.5 else 0]

    def h_1f8(e, rr):
        e.calllog.append(('self.1f8', e.arg32(0)))
        e.ret(eax=ans[0], argbytes=4)

    only_hooks(c, {})
    self = vt_object(c, 0x3000, {0x1f8: h_1f8}, nslots=0x100, name='self')
    idx = r.choice([0, 1, 2, 7, r.randint(0, 40)])
    e.w8(self + 5 * idx + 0xa0b, 0x80 if r.random() < 0.3 else r.getrandbits(8))   # 0x80: the boundary of the top-bit test
    const = e.rf32(0x6785d0)
    g = rnd(c, 0x1b00)
    e.w32(0x70039c, g)
    ch = r.random()
    e.wf32(g + 0x9c7, const if ch < 0.4 else (const + 1.0 if ch < 0.7 else float('nan')))
    return [self, idx]


S(0x41ede0, 'ZSysMem::IsMallocSimple (named)', 'thiscall', None, ret='eax', gen=_gen_malloc, note='area50 batch900 (band slice)')
S(0x420170, 'ZSysInterfaceGC::GetCharacter (named)', 'thiscall', None, ret='al', gen=_gen_char, note='area50 batch900 (band slice)')
