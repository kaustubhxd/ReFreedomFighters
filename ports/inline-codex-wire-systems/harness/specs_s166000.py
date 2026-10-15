from pilot import S
def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _command(c):
    # this+0x44: a logging object (vtable slot +0x12c takes 3 stack args); word +0x48 equals the argument's low word in
    # a third of the cases, a third with high bits set, a third random
    vt = c.emu.logging_vtable('relay-target', 0x130, argwords={0x12c: 3})
    target = _rnd(c, 0x40)
    c.emu.w32(target, vt)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x44, target)
    word = c.rng.randint(0, 0xffff)
    c.emu.w16(self_ + 0x48, word)
    r = c.rng.random()
    if r < 0.33:
        arg = word
    elif r < 0.66:
        arg = word | (c.rng.getrandbits(16) << 16)
    else:
        arg = c.rng.getrandbits(32)
    return [self_, arg, _rnd(c, 0x20)]


S(0x4b85c0, 'ZRelayMessage::Command', 'thiscall', None, ret='eax', gen=_command, note='Heap and virtual target, all three forwarded arguments compared; virtual dispatch is an explicit logging stand-in.')
