"""specs_u69_97.py - area 69, residue-8 (batch 97).
0x5f51c0: thiscall, one stack arg; calls vt[0] on self+0xaca (thiscall, two args, pops 8; fake vtable, GUESS).
0x64d000: thiscall, one stack arg; calls vt[2] on [self+0x10165] (no args; fake vtable, GUESS), links the result into p.
0x5650c0: thiscall, no args; calls vt[3] on [self+0xade] (two args, pops 8; fake vtable, GUESS), stores AL at self+8.
0x60fe80: no args; reads globals 0x724950/0x72495c, calls vt[0xc8/4] on the device at 0x724a00 (COM stdcall, 3 args, GUESS).
0x557880: stdcall, one unused arg; 0x634d10 (cdecl memset shape) is a logging GUESS hook; vt[0] on [0x713f04] is a fake."""
from pilot import S
from ckit import rnd, rvt


def _call(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0xb00)
    a = r.getrandbits(32)
    val = r.getrandbits(32)
    vt = rvt(e, 'sub5f51c0', {0: (2, lambda e, ecx, args: (val, None, ('s', int(ecx == self_ + 0xaca), int(args[0] == a), args[1])), 8)}, nslots=4)
    e.w32(self_ + 0xaca, vt)
    return [self_, a]


def _push(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x10200)
    o = rnd(c, 0x20)
    R = rnd(c, 0x40)
    p = rnd(c, 0x40)
    vt = rvt(e, 'alloc64d000', {8: (0, lambda e, ecx, args: (R, None, ('a', int(ecx == o))), 0)}, nslots=4)
    e.w32(o, vt)
    e.w32(self_ + 0x10165, o)
    return [self_, p]


def _poll(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0xb40)
    o = rnd(c, 0x20)
    val = r.getrandbits(32)
    vt = rvt(e, 'poll5650c0', {0xc: (2, lambda e, ecx, args: (val, None, ('p', int(ecx == o), args[0], int(args[1] == self_ + 0xb0a))), 8)}, nslots=4)
    e.w32(o, vt)
    e.w32(self_ + 0xade, o)
    return [self_]


def _fog(c):
    e = c.emu
    r = c.rng
    v = r.getrandbits(32)
    e.w32(0x72495c, v)
    e.w32(0x724950, v if r.random() < 0.3 else r.getrandbits(32))
    dev = rnd(c, 0x20)
    vt = rvt(e, 'dev60fe80', {0xc8: (3, lambda e, ecx, args: (r.getrandbits(32), None, ('d', int(args[0] == dev), args[1], args[2])), 12)}, nslots=0x100 // 4)
    e.w32(dev, vt)
    e.w32(0x724a00, dev)
    return []


def _reset(c):
    e = c.emu
    r = c.rng
    e.wbytes(0x713e2c, bytes(r.getrandbits(8) for _ in range(0xdc)))
    p = 0
    if r.random() < 0.7:
        p = rnd(c, 0x20)
        vt = rvt(e, 'dtor557880', {0: (1, lambda e, ecx, args: (r.getrandbits(32), None, ('x', int(ecx == p), args[0])), 4)}, nslots=4)
        e.w32(p, vt)
    e.w32(0x713f04, p)

    def hook(e, res):
        e.calllog.append(('h634d10', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=e.arg32(0), argbytes=0)
    e.hook(0x634d10, hook)
    return [r.getrandbits(32)]


S(0x5f51c0, 'call5f51c0 (thiscall, vt[0] on self+0xaca)', 'thiscall', None, ret='eax', gen=_call,
  note='u69 residue-8 batch 97; vtable slot 0 is a fake (GUESS)')
S(0x64d000, 'push64d000 (thiscall, list push onto arg)', 'thiscall', None, ret='eax', gen=_push,
  note='u69 residue-8 batch 97; vtable slot 8 is a fake (GUESS)')
S(0x5650c0, 'poll5650c0 (thiscall, stores vt[3] AL at +8)', 'thiscall', None, ret=None, gen=_poll,
  note='u69 residue-8 batch 97; vtable slot 0xc is a fake (GUESS)')
S(0x60fe80, 'fog60fe80 (global compare, device vt[0xc8])', 'cdecl', None, ret=None, gen=_fog,
  note='u69 residue-8 batch 97; device vtable slot 0xc8 is a fake (GUESS, SetRenderState shape)')
S(0x557880, 'reset557880 (stdcall, clears 0x713e30 block)', 'stdcall', None, ret=None, gen=_reset,
  note='u69 residue-8 batch 97; 0x634d10 is a GUESS hook (memset shape), vt[0] on [0x713f04] is a fake')
