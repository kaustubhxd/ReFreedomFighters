"""specs_s32.py - inline session batch 32 (Haiku, night): 0x5e3dd0 GetAnimFromStatus (virtual calls to exe code)."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


BASEMOVE_VT = 0x6b75a0   # ZFFHeroMovementBaseMove vtable: slot 0x60 GetActiveWalkDefsList, 0x64 GetActiveRunDefsList
ANIMLIST_VT = 0x68b604   # ZAnimDefsList vtable: slot 0x10 at 0x4837e0


def _recorder(c, nargs, ret):
    # heap code stub: copy the nargs stack args into a buffer, bump a call counter, 'ret ret' (same as specs_s45)
    buf = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', buf + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', buf + 4 * nargs) + b'\xc2' + struct.pack('<H', ret)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _iterlist(c):
    # A REFTAB list for GetAnim 0x4837e0: slot 0x4c (start, one stack arg = a pointer to the caller's iterator) just
    # returns; slot 0x64 (next) returns entries in order, then 0. Neither logs its argument (a stack address, which
    # differs between the two builds' frames). Entry = {anim pointer, id}; GetAnim stops at the entry whose id is its arg.
    r = c.rng
    ents = []
    for _ in range(r.randint(1, 4)):
        e = c.emu.alloc(8, 4)
        anim = _rnd(c, 0x10)
        if r.random() < 0.1:
            c.emu.w32(anim, 0xedededed)
        c.emu.w32(e, anim)
        c.emu.w32(e + 4, r.randint(1, 4))
        ents.append(e)
    ents.append(0)
    tab = c.emu.alloc(4 * 8, 4)
    for i in range(8):
        c.emu.w32(tab + 4 * i, ents[min(i, len(ents) - 1)])
    cnt = c.emu.alloc(4, 4)
    code = (b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\x8b\x04\x85' + struct.pack('<I', tab)
            + b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2\x04\x00')
    nxt = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(nxt, code)
    start = c.emu.alloc(16, 16)
    c.emu.wbytes(start, b'\xc2\x04\x00')
    vt = c.emu.alloc(0x68, 4)
    c.emu.w32(vt + 0x4c, start)
    c.emu.w32(vt + 0x64, nxt)
    lst = c.emu.alloc(8, 4)
    c.emu.w32(lst, vt)
    return lst


def _lists(c, obj):
    # 2026-10-13 (wire-hero-combat): the generator fix for docs/39's faulting cases. GetAnimFromStatus reaches the
    # ZAnimDefsList objects EMBEDDED in this (GetActiveWalk/RunDefsList 0x5e3da0 / 0x5e3d60 return this+0x25, 0x3d,
    # 0x3d3, 0x3eb or 0x4ab; bit 0x10000000 takes this+0x523), so their vtables were random bytes. Same setup as
    # specs_s45 (Move). GetAnim 0x4837e0 also reads [0x70039c]+0x40, so the system object is mapped too.
    r = c.rng
    for off in (0x25, 0x3d, 0x3d3, 0x3eb, 0x4ab, 0x523):
        c.emu.w32(obj + off, ANIMLIST_VT)
        c.emu.w32(obj + off + 0x14, _iterlist(c) if r.random() < 0.5 else 0)   # 0: GetAnim returns its +4
        x = r.random()
        if x < 0.1:
            anim = 0                       # no anim: no 0xedededed check
        else:
            anim = _rnd(c, 0x10)
            if x < 0.25:
                c.emu.w32(anim, 0xedededed)   # freed-memory mark: the assert hook path
        c.emu.w32(obj + off + 4, anim)
    sysobj = _rnd(c, 0x100)
    c.emu.w32(sysobj + 0x40, r.randint(0, 4096))
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(0x7003b0, _recorder(c, 0, 0))   # the hook is always set (docs/41 rule: no int3 cases)


def _gas(c):
    r = c.rng
    obj = _rnd(c, 0x800)
    c.emu.w32(obj, BASEMOVE_VT)
    p = _rnd(c, 0x500)
    c.emu.w32(p + 0x417, r.getrandbits(32))
    c.emu.w32(obj + 4, p)
    _lists(c, obj)
    c.emu.mu.ctl_flush_tb()
    return [obj, r.getrandbits(32)]


S(0x5e3dd0, 'ZFFHeroMovementBaseMove::GetAnimFromStatus', 'thiscall', None, ret='eax', gen=_gas,
  note='batch32; calls through the exe vtables (BaseMove slots 0x60/0x64, ZAnimDefsList slot 0x10); status bits pick the path')
