"""Stateful callback contract: callback may replace member/value before helper call."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub

def g486190(c):
    clear_hooks(c)
    r = c.rng
    mode = c.case % 8
    self = rnd(c, 0x100)
    initial = rnd(c, 0x80)
    replacement = self if mode == 7 else rnd(c, 0x80)
    values = [0, 1, 0x7fffffff, 0x80000000, 0xffffffff]
    value = values[c.case % len(values)] if mode < 5 else r.getrandbits(32)
    newvalue = value ^ 0xa5c39e71
    c.emu.w32(self + 12, value)
    c.emu.w32(self + 16, initial)

    def callback(e, k):
        e.calllog.append(('callback', mode, e.reg('ecx'), e.arg32(0), e.arg32(1)))
        if mode & 1:
            e.w32(self + 12, newvalue)
        if mode & 2:
            e.w32(self + 16, replacement)
        # Unrelated field also changes; compare full heap, no masks.
        e.w32(self + 0x20, e.r32(self + 0x20) ^ 0x12345678)

    def helper(e, k):
        args = tuple(e.arg32(i) for i in range(6))
        e.calllog.append(('helper', e.reg('ecx'), args))
        checksum = 0x6d2b79f5
        for arg in args:
            checksum = ((checksum << 5) | (checksum >> 27)) & 0xffffffff
            checksum ^= arg
        # Side effects depend on all forwarded values and the actual receiver.
        e.w32(e.reg('ecx'), checksum)
        e.w32(e.reg('ecx') + 4, k + 1)

    hook_rec(c, 0x467410, 6, ret=r.getrandbits(32), pop=24, this=True, side=helper)
    vt = rnd(c, 0x300)
    c.emu.w32(vt + 0x2d0, pystub(c, 2, ret=r.getrandbits(32), this=True, side=callback))
    target = rnd(c, 0x80)
    c.emu.w32(target, vt)
    c.emu.w32(self + 8, target)
    return [self]

S(0x486190, 'ZActionPushButton::CallBack', 'thiscall', None, ret='al', gen=g486190,
  reg_values=True, note='batch266000 Codex stateful callback reload + helper writes; 8 modes')
