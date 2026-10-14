"""specs_s909.py - residue-9 slice, batch 909: four short bodies.
0x5f3290 (thiscall, one arg = pointer to a dword, ret 4): slot +0x5c of the object at this+0x15 with the dword. Stand-in: that slot (logs
its argument, pops 4). 0x4b1850 (thiscall, u16 + pointer, ret 8, returns 0): writes this+0x4a to *out when the word matches this+0x48.
0x4cb4d0 (thiscall, one arg = save object, ret 4, returns 1): clears bit 6 of this+4 and calls the save object's slot +0x44 with
this+0x4c (stand-in, logs, pops 4). 0x64a6d0 (cdecl, two pointers, returns 1 or -1). The compare word is drawn equal or not."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_5f(c):
    e, r = c.emu, c.rng
    def h5c(e, rr):
        e.calllog.append(('o.5c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    o = vt_object(c, 0x40, {0x5c: h5c}, nslots=0x40, name='o')
    self = rnd(c, 0x40)
    e.w32(self + 0x15, o)
    arg = rnd(c, 0x10)
    return [self, arg]


def _gen_4b(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x80)
    key = r.getrandbits(16)
    e.w16(self + 0x48, key)
    e.w8(self + 0x4a, r.getrandbits(8))
    cmd = key if r.random() < 0.5 else (key ^ 1) & 0xffff
    out = rnd(c, 0x10)
    return [self, cmd, out]


def _gen_4c(c):
    e, r = c.emu, c.rng
    def h44(e, rr):
        e.calllog.append(('save.44', e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    save = vt_object(c, 0x40, {0x44: h44}, nslots=0x40, name='save')
    self = rnd(c, 0x80)
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 0x4c, r.getrandbits(32))
    return [self, save]


def _gen_64(c):
    e, r = c.emu, c.rng
    a = rnd(c, 0x10)
    b = rnd(c, 0x10)
    e.w32(a, r.getrandbits(32))
    e.w32(b, r.choice([0, 1, 0xffffffff, r.getrandbits(32)]))
    if r.random() < 0.3:
        e.w32(b, e.r32(a))
    return [a, b]


S(0x5f3290, 'SaveSerialInfo_t::savestring (named)', 'thiscall', None, gen=_gen_5f, note='area50 batch909 (residue-9 slice)')
S(0x4b1850, 'ZCutSeqDeleteObj::Command (named)', 'thiscall', None, ret='eax', gen=_gen_4b, note='area50 batch909 (residue-9 slice)')
S(0x4cb4d0, 'ZViewNotifyCheckBox::Save (named)', 'thiscall', None, ret='al', gen=_gen_4c, note='area50 batch909 (residue-9 slice)')
S(0x64a6d0, 'cmp64a6d0 (no name in map)', 'cdecl', None, ret='eax', gen=_gen_64, note='area50 batch909 (residue-9 slice)')
