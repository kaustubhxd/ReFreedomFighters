"""specs_u69_96.py - area 69, residue-8 (batch 96).
0x665240: frame-based plain ret (frame values at [ebp-0x10], [ebp-0x14]); its callee 0x4690b0 (cdecl, two args) is a logging GUESS hook.
0x656d80: thiscall, two stack args, ret 8; its vtable slot 0xc (one stack arg, callee pops 4) is a fake vtable in the spec (GUESS)."""
from pilot import S
from ckit import rnd, rvt


def _frame(c):
    e = c.emu
    r = c.rng
    buf = rnd(c, 0x100)
    ebp = buf + 0x80
    v10, v14 = r.getrandbits(32), r.getrandbits(32)
    e.w32(ebp - 0x10, v10)
    e.w32(ebp - 0x14, v14)
    val = r.getrandbits(32)

    def hook(e, res):
        e.calllog.append(('h4690b0', int(e.arg32(0) == v10), int(e.arg32(1) == v14)))
        e.ret(eax=val, argbytes=0)
    e.hook(0x4690b0, hook)
    return [ebp]


def _store(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x40)
    a, b = r.getrandbits(32), r.getrandbits(32)
    R = rnd(c, 0x40)
    vt = rvt(e, 'storeSelf', {0xc: (1, lambda e, ecx, args: (R, None, ('c', int(ecx == self_), int(args[0] == a))), 4)}, nslots=0x40 // 4)
    e.w32(self_, vt)
    return [self_, a, b]


S(0x665240, 'fwd665240 (frame-based, calls 0x4690b0 GUESS hook)', ('regs', ['ebp']), None, ret='eax', gen=_frame,
  note='u69 residue-8 batch 96; 0x4690b0 is a GUESS hook')
S(0x656d80, 'store656d80 (thiscall, two stack args, ret 8)', 'thiscall', None, ret=None, gen=_store,
  note='u69 residue-8 batch 96; vtable slot 0xc is a fake (GUESS)')
