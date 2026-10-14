"""specs_f1001.py - fresh-10 batch 1: eight small slice-10 wrappers (vtable tail calls, one import, one dtor body)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h10 import L, obj, rbuf, patch


def g_650c20(c):   # ZRender::RemoveView(ZViewBase*): tail vt[0x30] of the object at this+0xbd
    inner = obj(c, 'view', {0x30: L('vt30', 1, ret=c.rng.getrandbits(32))})
    o = rbuf(c, 0x200)
    c.emu.w32(o + 0xbd, inner)
    return [o, c.rng.getrandbits(32)]
S(0x650c20, 'ZRender::RemoveView', 'thiscall', None, ret='eax', gen=g_650c20)


def g_601c60(c):   # CHostInterface::notifyRecycleProcess(Process_t*): tail [0x7003a4] vt[0xa8]
    host = obj(c, 'host', {0xa8: L('vta8', 1, ret=c.rng.getrandbits(32))})
    c.emu.w32(0x7003a4, host)
    return [rbuf(c, 0x40), c.rng.getrandbits(32)]
S(0x601c60, 'CHostInterface::notifyRecycleProcess', 'thiscall', None, ret='eax', gen=g_601c60)


def g_655360(c):   # GUESS: ShowWindow(this+0x133 hwnd, arg)
    s = c.emu.stub_fn('ShowWindow', L('ShowWindow', 2, ret=c.rng.getrandbits(32), ecx=False))
    c.emu.w32(0x676198, s)
    return [rbuf(c, 0x200), c.rng.getrandbits(32)]
S(0x655360, 'GUESS ShowWindow(this+0x133, arg)', 'thiscall', None, ret='eax', gen=g_655360)


def g_54e160(c):   # GUESS dtor body: vtable 0x6a3ea8, delete(this+0x53, 1)
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    o = rbuf(c, 0x100)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x53, 0)
    return [o]
S(0x54e160, 'GUESS dtor body (vtable 0x6a3ea8, delete +0x53)', 'thiscall', None, ret=None, gen=g_54e160)


def g_63e660(c):   # ZDrawBase::FreeSprites(void*, int)
    o = obj(c, 'draw', {0x24: L('vt24', 2, ret=c.rng.getrandbits(32))})
    return [o, c.rng.getrandbits(32), c.rng.choice([0, 1, 15, 16, 17, 0xfffffff1, c.rng.getrandbits(32)])]
S(0x63e660, 'ZDrawBase::FreeSprites', 'thiscall', None, ret='eax', gen=g_63e660)


def _getlight(slot):
    def g(c):
        o = obj(c, 'prim', {slot: L('vt%x' % slot, 2, ret=c.rng.getrandbits(32))})
        return [o, rbuf(c, 0x60), rbuf(c, 0x60)]
    return g
S(0x6564e0, 'ZPrimControlBase::GetLightDirectionalData', 'thiscall', None, ret='eax', gen=_getlight(0x148))
S(0x656620, 'ZPrimControlBase::GetLightSpotSquareData', 'thiscall', None, ret='eax', gen=_getlight(0x150))


def g_656b20(c):   # GUESS: vt[0x94](this, vt[0xc](this, a), b)
    o = obj(c, 'o', {0xc: L('vtc', 1, ret=c.rng.getrandbits(32)), 0x94: L('vt94', 2, ret=c.rng.getrandbits(32))})
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]
S(0x656b20, 'GUESS vt94(vtc(a), b)', 'thiscall', None, ret='eax', gen=g_656b20)
