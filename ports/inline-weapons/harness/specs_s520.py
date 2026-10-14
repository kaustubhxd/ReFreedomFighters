"""specs_s520.py - weapons batch 520: small ZLNKWHANDS members."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, patch_jmp, vec, fedge


def _h(c, slots=None):
    r = c.rng
    s = obj(c, 0x600, slots or {})
    for off in (0x2e7, 0x34f):
        vt = c.emu.alloc(0x40, 4)
        c.emu.w32(vt + 0x1c, stub(c, 8, rec_ecx=True))
        c.emu.w32(s + off, vt)
    return s


def _plain(c):
    return [_h(c)]


def _b(c):
    return [_h(c), c.rng.choice((0, 1, 2, 0x100, 0xff))]


def _u(c):
    return [_h(c), c.rng.getrandbits(32)]


def _reset(c):
    patch_jmp(c, 0x467710, stub(c, 0, rec_ecx=True))
    patch_jmp(c, 0x466220, stub(c, 0, rec_ecx=True))
    return [_h(c)]


def _near(c):
    r = c.rng
    l = obj(c, 0x40, {0x28: stub(c, 1, ret=b(c, 0.4) & 0xff if r.random() < 0.5 else r.choice((0, 0x100))),
                      0x3c: stub(c, 1)})
    s = _h(c)
    c.emu.w32(s + 0x3b7, 0 if r.random() < 0.2 else l)
    return [s, r.getrandbits(32)]


def _setik(c):
    r = c.rng
    return [_h(c), r.getrandbits(32), r.getrandbits(32), F(r.uniform(0, 2)), r.getrandbits(32), r.getrandbits(32),
            r.getrandbits(32), r.getrandbits(32)]


def _remik(c):
    r = c.rng
    patch_jmp(c, 0x467410, stub(c, 6, rec_ecx=True))
    return [_h(c), F(r.uniform(0, 2)), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _upd(c):
    patch_jmp(c, 0x467f60, stub(c, 0, rec_ecx=True))
    patch_jmp(c, 0x467cd0, stub(c, 1, rec_ecx=True))
    return [_h(c, {0x4a8: stub(c, 0)})]


def _dialog(c):
    r = c.rng
    return [_h(c, {0x230: stub(c, 2)}), r.choice((-1 & 0xffffffff, 0, 1, 2, 3, 4, 100, r.getrandbits(32)))]


def _getdm(c):
    r = c.rng
    s = _h(c)
    bone = r.choice(list(range(10)) + [10, 255])
    if bone > 9:
        c.emu.w32(0x7003b0, stub(c, 0))
    return [s, bone | (r.getrandbits(24) << 8)]


def _setdm(c):
    r = c.rng
    return [_h(c), r.choice(list(range(10)) + [10, 255]) | (r.getrandbits(24) << 8), r.getrandbits(32)]


S(0x4744e0, 'ZLNKWHANDS::GetRHand', 'thiscall', None, ret='eax', gen=_plain)
S(0x474440, 'ZLNKWHANDS::GetLHand', 'thiscall', None, ret='eax', gen=_plain)
S(0x4743e0, 'ZLNKWHANDS::GetInventoryList', 'thiscall', None, ret='eax', gen=_plain)
S(0x4744b0, 'ZLNKWHANDS::GetNearItems', 'thiscall', None, ret='eax', gen=_plain)
S(0x474310, 'ZLNKWHANDS::GetDialog', 'thiscall', None, ret='al', gen=_plain)
S(0x475910, 'ZLNKWHANDS::SetDialog', 'thiscall', None, ret=None, gen=_b)
S(0x475930, 'ZLNKWHANDS::SetHitAnimation', 'thiscall', None, ret=None, gen=_u)
S(0x475300, 'ZLNKWHANDS::Reset', 'thiscall', None, ret=None, gen=_reset)
S(0x475280, 'ZLNKWHANDS::RemoveNearItem', 'thiscall', None, ret=None, gen=_near)
S(0x475940, 'ZLNKWHANDS::SetLHandIKTarget', 'thiscall', None, ret=None, gen=_setik)
S(0x4759b0, 'ZLNKWHANDS::SetRHandIKTarget', 'thiscall', None, ret=None, gen=_setik)
S(0x475250, 'ZLNKWHANDS::RemoveLHandIKTarget', 'thiscall', None, ret=None, gen=_remik)
S(0x4752b0, 'ZLNKWHANDS::RemoveRHandIKTarget', 'thiscall', None, ret=None, gen=_remik)
S(0x4760d0, 'ZLNKWHANDS::UpdateTargets', 'thiscall', None, ret=None, gen=_upd)
S(0x4739b0, 'ZLNKWHANDS::DialogListen', 'thiscall', None, ret=None, gen=_dialog)
S(0x4739e0, 'ZLNKWHANDS::DialogTalk', 'thiscall', None, ret=None, gen=_dialog)
S(0x474250, 'ZLNKWHANDS::GetDamageMultForBone', 'thiscall', None, ret='st0', gen=_getdm)
S(0x475820, 'ZLNKWHANDS::SetDamageMultForBone', 'thiscall', None, ret=None, gen=_setdm)
