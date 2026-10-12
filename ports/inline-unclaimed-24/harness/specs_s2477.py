"""specs_s2477.py - decomp area 24, batch 2477.
0x44cad0 ~ZBoneParticle (vtable 0x6801a4) and 0x44cb60 ~ZMotionBlur (vtable 0x6807f8): the vtable is stored, then the base
destructor (0x43de70, recorder), then flag bit 0: SetState(this, 0x24 or 0x4b0) when bit 2 (0x4690b0, recorder, cdecl), else
operator delete (0x45c510, recorder, cdecl). Thiscall, ret 4, eax = this.
0x4489c0 ZGateLightOmni::CopyDataBlock(DBLK*), thiscall, ret 4: ZLIGHT::CopyDataBlock (0x448a30, recorder), NextBlock (0x4e1b30,
recorder), DBLK::Get into this+0x1c and this+0x20 with count 1 (0x4e12e0, recorder), NextBlock."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _dtor(base):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 0, this=True)
        hook_rec(c, 0x4690b0, 2, pop=0)
        hook_rec(c, 0x45c510, 1, pop=0)
        return [rnd(c, 0x100), r.getrandbits(32)]
    return gen


def _omni(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x448a30, 1, this=True)
    hook_rec(c, 0x4e12e0, 2, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x44cad0, 'ZBoneParticle::~ZBoneParticle', 'thiscall', None, ret='eax', gen=_dtor(0x43de70), note='batch2477')
S(0x44cb60, 'ZMotionBlur::~ZMotionBlur', 'thiscall', None, ret='eax', gen=_dtor(0x43de70), note='batch2477')
S(0x4489c0, 'ZGateLightOmni::CopyDataBlock', 'thiscall', None, ret=None, gen=_omni, note='batch2477')
