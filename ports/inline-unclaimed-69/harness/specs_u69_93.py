"""specs_u69_93.py - area 69, residue-8 forwarders into SEH-framed functions (listed as forwarders, not verified bodies).
Each forwarder takes EBP through the ('regs', ['ebp']) ABI with a frame buffer in emulator memory; the target is a GUESS hook
that logs whether ECX is the expected pointer and returns a random eax. The target bodies (SEH frames) are not checked."""
from pilot import S
from ckit import rnd


def _g668d08(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0x4c
    e.hook(0x4ccf60, lambda e, res: (e.calllog.append(('tgt4ccf60', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x668d08, 'fwd668d08 (forwarder to 0x4ccf60, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g668d08, note='u69 forwarder; target 0x4ccf60 is a GUESS hook')

def _g668d13(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0xfc
    e.hook(0x4ccf60, lambda e, res: (e.calllog.append(('tgt4ccf60', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x668d13, 'fwd668d13 (forwarder to 0x4ccf60, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g668d13, note='u69 forwarder; target 0x4ccf60 is a GUESS hook')

def _g66c408(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0x84
    e.hook(0x4ccf60, lambda e, res: (e.calllog.append(('tgt4ccf60', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66c408, 'fwd66c408 (forwarder to 0x4ccf60, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g66c408, note='u69 forwarder; target 0x4ccf60 is a GUESS hook')

def _g66c906(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0x3eb
    e.hook(0x480fd0, lambda e, res: (e.calllog.append(('tgt480fd0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66c906, 'fwd66c906 (forwarder to 0x480fd0, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g66c906, note='u69 forwarder; target 0x480fd0 is a GUESS hook')

def _g66a108(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0x2d8
    e.hook(0x511950, lambda e, res: (e.calllog.append(('tgt511950', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66a108, 'fwd66a108 (forwarder to 0x511950, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g66a108, note='u69 forwarder; target 0x511950 is a GUESS hook')

def _g66ce04(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    obj = rnd(c, 0x800)
    e.w32(ebp - 0x10, obj)
    val = c.rng.getrandbits(32)
    exp = obj + 0xac
    e.hook(0x5a5440, lambda e, res: (e.calllog.append(('tgt5a5440', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66ce04, 'fwd66ce04 (forwarder to 0x5a5440, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g66ce04, note='u69 forwarder; target 0x5a5440 is a GUESS hook')

def _g665101(c):
    e = c.emu
    buf = rnd(c, 0x4000)
    ebp = buf + 0x3f00
    exp = ebp + (-0x3f9c)
    val = c.rng.getrandbits(32)
    e.hook(0x42ba10, lambda e, res: (e.calllog.append(('tgt42ba10', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x665101, 'fwd665101 (forwarder to 0x42ba10, SEH-framed target hooked)', ('regs', ['ebp']), None, ret='eax', gen=_g665101, note='u69 forwarder; target 0x42ba10 is a GUESS hook')
