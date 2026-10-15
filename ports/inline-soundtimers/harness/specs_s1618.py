"""specs_s1618.py - soundtimers batch 1618: GetWaveDuration (both forms), FindObjectIdx."""
import fnmatch
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, HOOKED
from specs_s1614 import _block


def _wavew(c):
    w = rnd(c, 0x10) if c.rng.random() < 0.9 else 0
    if w:
        c.emu.wf32(w + 0xc, c.rng.uniform(0, 8))
    return [rnd(c, 0x10), w]


S(0x537860, 'ZDllSound::GetWaveDuration(SWave*)', 'thiscall', None, ret='st0', gen=_wavew, note='batch1618')


def _dur(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    f = c.emu.alloc(4, 4)
    c.emu.wf32(f, r.uniform(0, 8))
    d = obj(c, 0x5400, {0x1e0: stub(c, seq, 1, fld=f), 0x1e8: stub(c, seq, 1, ret=r.getrandbits(32))})
    b = _block(c)
    c.emu.w32(d + 0x5302, b if r.random() < 0.9 else 0)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    return [d, r.choice([0x40, 0x80, 0xc0, 0x100])]


S(0x5377d0, 'ZDllSound::GetWaveDuration(int)', 'thiscall', None, ret='st0', gen=_dur, note='batch1618')


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 4, 4)
    c.emu.wbytes(a, s.encode() + b'\0')
    return a


def _find(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)

    def strw(e, rr):
        a = bytes(e.rbytes(e.reg('ecx'), 24)).split(b'\0')[0].decode('latin-1').lower()
        p = bytes(e.rbytes(e.reg('edx'), 24)).split(b'\0')[0].decode('latin-1').lower()
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=0 if fnmatch.fnmatchcase(a, p) else 1)
    c.emu.hook(0x4cc850, strw)
    HOOKED.add(0x4cc850)
    d = rnd(c, 0x5400)
    b = rnd(c, 0x400, 16)
    c.emu.w32(d + 0x5302, b if r.random() < 0.95 else 0)
    n = r.randint(0, 6)
    names = ['Default', 'Wood', 'Asphalt', 'Snow', 'Metal', 'Water']
    for i in range(n):
        rec = 0x100 + 0x20 * i
        c.emu.w32(b + 0x40 + 4 * i, rec)
        c.emu.w32(b + rec + 4, 0x300 + 0x10 * i)
        c.emu.wbytes(b + 0x300 + 0x10 * i, r.choice(names).encode() + b'\0')
    nm = r.choice([0, _cstr(c, ''), _cstr(c, 'Default'), _cstr(c, 'snow'), _cstr(c, 'Mud')])
    return [d, 0x40, n, nm]


S(0x5367c0, 'ZDllSound::FindObjectIdx', 'thiscall', None, ret='eax', gen=_find, note='batch1618')
