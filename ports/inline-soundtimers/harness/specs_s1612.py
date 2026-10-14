"""specs_s1612.py - soundtimers batch 1612: ZDllSound::FindInSoundSet and GetIdxFromSoundSet(_Rec).
A fake sound-data block holds one sound set with up to 6 members; each member is {name pointer} and the DLL's
+0x1e8 (member name) is a Python stub returning it. striwcmp (0x4cc850, batch 54) is hooked by a Python
case-insensitive wildcard match (deterministic; the checker only needs both runs to see the same answers)."""
import fnmatch
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, HOOKED

NAMES = ['Soviet_M1_Panic_01', 'Soviet_M1_Pain', 'Civ_Generic_03', 'Hero_Attack', 'Hero_All_1', 'x']
PATS = ['*Panic*', '*Pain*', '*Generic*', '*_Attac', '*_All*', '*Nothing*', '', '*']


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 4, 4)
    c.emu.wbytes(a, s.encode() + b'\0')
    return a


def _world(c, seq):
    r = c.rng
    clear_hooks(c)

    def strw(e, rr):
        a = bytes(e.rbytes(e.reg('ecx'), 40)).split(b'\0')[0].decode('latin-1').lower()
        b = bytes(e.rbytes(e.reg('edx'), 40)).split(b'\0')[0].decode('latin-1').lower()
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=0 if (b and fnmatch.fnmatchcase(a, b)) else 0xffffffff)
    c.emu.hook(0x4cc850, strw)
    HOOKED.add(0x4cc850)

    def name(e, rr):
        m = e.r32(e.reg('esp') + 4)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=e.r32(m), argbytes=4)
    base = c.emu.alloc(0x400, 16)
    n = r.randint(0, 6)
    st = 0x40
    c.emu.w32(base + st, r.choice([3, 3, 3, 2]))
    c.emu.w16(base + st + 8, n)
    tab = 0x80
    c.emu.w32(base + st + 0x10, tab if r.random() < 0.95 else 0)
    for i in range(n):
        m = 0x100 + 0x10 * i
        c.emu.w32(base + tab + 4 * i, m if r.random() < 0.95 else 0)
        c.emu.w32(base + m, _cstr(c, r.choice(NAMES)) if r.random() < 0.95 else 0)
    slots = {0x1e8: c.emu.stub_fn('MemberName', name), 0x1c0: stub(c, seq, 1, ret=r.getrandbits(32)),
             0x1c4: stub(c, seq, 3, ret=r.getrandbits(32))}
    d = obj(c, 0x5400, slots)
    c.emu.w32(d + 0x5302, base if r.random() < 0.95 else 0)
    ch = obj(c, 0x40, {0x30: stub(c, seq, 2, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    return d, base + st


def _get(c):
    seq = Seq(c)
    d, st = _world(c, seq)
    r = c.rng
    return [d, st if r.random() < 0.95 else 0, _cstr(c, r.choice(PATS)) if r.random() < 0.95 else 0]


S(0x5370d0, 'ZDllSound::GetIdxFromSoundSet', 'thiscall', None, ret='eax', gen=_get, note='batch1612')


def _getr(c):
    a = _get(c)
    return a + [c.rng.choice([0, 1, 2, 3])]


S(0x537160, 'ZDllSound::GetIdxFromSoundSet_Rec', 'thiscall', None, ret='eax', gen=_getr, note='batch1612')


def _find(c):
    seq = Seq(c)
    d, st = _world(c, seq)
    r = c.rng
    base = c.emu.r32(d + 0x5302)
    idx = (st - base) & 0xffffffff if base else 0x40
    idx = r.choice([idx, idx, idx, 0, 0x100])
    return [d, idx, _cstr(c, r.choice(PATS)) if r.random() < 0.95 else 0]


S(0x536650, 'ZDllSound::FindInSoundSet', 'thiscall', None, ret='eax', gen=_find, note='batch1612')
