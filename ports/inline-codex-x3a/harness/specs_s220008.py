"""Strict broad fixture for 0x5edf70's escaped-name notification paths."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g5edf70(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    self = rnd(c, 0xc0)
    payloads = (
        b'\0', b'a\0', b'ab\0', b'pre\\npost\0',
        b'a\\nb\\nc\0', b'xx\\n\0', b'x\\ny\\nz\0',
    )
    payload = payloads[c.case % len(payloads)]
    text = rnd(c, len(payload) + 16)
    e.wbytes(text, payload)

    # The notification code owns a vector of (listener, payload) entries.
    # Four slots cover every generated escaped segment.
    slots = rnd(c, 4 * 4)
    for i in range(4):
        entry = rnd(c, 8)
        listener = rnd(c, 0x100)
        e.w32(entry, listener)
        e.w32(entry + 4, r.getrandbits(32))
        e.w32(slots + 4 * i, entry)
    e.w32(self + 5, slots)
    e.w32(self + 9, slots + 16)
    e.w32(self + 0x11, r.choice([0, 1, r.getrandbits(32)]))
    e.w32(self + 0x19, r.choice([0, 1]))
    e.w32(self + 0x41, r.getrandbits(32))
    e.w32(self + 0x45, r.getrandbits(32))
    e.w32(self + 0x6a, c.case & 1)
    e.w32(self + 0x77, r.getrandbits(32))
    a1 = r.getrandbits(32)

    def resize_side(emu, _k):
        emu.calllog.append(('resize-count', emu.r32(emu.reg('ecx') + 0x19)))

    def parse_side(emu, _k):
        p, n = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('escaped-segment', emu.rbytes(p, min(n, 16))))

    def notify_side(emu, k):
        a0, a1_, a2 = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('notify-args', emu.reg('ecx'), a0, a1_, a2, k))
        emu.w32(emu.reg('ecx') + 0x80, a0 ^ a1_ ^ a2 ^ (0x5a5a0000 + k))

    hook_rec(c, 0x5ee920, 0, ret=0, this=True, side=resize_side)
    hook_rec(c, 0x5aca30, 2, ret=0, this=True, side=parse_side)
    hook_rec(c, 0x5ac5d0, 1, ret=0, this=True)
    hook_rec(c, 0x5ab9d0, 0, ret=lambda _e, k: (k * 7 + 3), this=True)
    hook_rec(c, 0x5ee110, 3,
             ret=lambda emu, _k: emu.arg32(1) ^ emu.arg32(2) ^ 0x91370000,
             pop=12, this=True, side=notify_side)
    return [self, text, a1]


S(0x5edf70, 'notify_escaped_name', 'thiscall', None, ret='eax',
  gen=g5edf70, note='batch220008 escaped-name and listener-vector fixture')
