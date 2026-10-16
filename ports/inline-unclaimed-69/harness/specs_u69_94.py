"""specs_u69_94.py - area 69, residue-8 forwarders (listed separately). Frame buffer through ('regs', ['ebp']); each target is a GUESS hook that
logs whether ECX is the expected pointer and returns a random eax. The targets are not verified bodies."""
from pilot import S
from ckit import rnd


def _g664acc(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x9c), obj)
    exp = obj + 0x6a3
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x664acc, 'fwd664acc (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g664acc, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g666dcb(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x90)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x666dcb, 'fwd666dcb (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g666dcb, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g667b83(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x310)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x667b83, 'fwd667b83 (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g667b83, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g667b8e(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x210)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x667b8e, 'fwd667b8e (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g667b8e, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g66844c(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x1b4)
    val = c.rng.getrandbits(32)
    e.hook(0x4f6b20, lambda e, res: (e.calllog.append(('tgt4f6b20', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66844c, 'fwd66844c (forwarder to 0x4f6b20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66844c, note='u69 forwarder; target 0x4f6b20 is a GUESS hook')

def _g669ac0(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x90)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x669ac0, 'fwd669ac0 (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g669ac0, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g669e80(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x40d4)
    val = c.rng.getrandbits(32)
    e.hook(0x4d2330, lambda e, res: (e.calllog.append(('tgt4d2330', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x669e80, 'fwd669e80 (forwarder to 0x4d2330, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g669e80, note='u69 forwarder; target 0x4d2330 is a GUESS hook')

def _g66a605(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0xbc)
    val = c.rng.getrandbits(32)
    e.hook(0x4ccf60, lambda e, res: (e.calllog.append(('tgt4ccf60', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66a605, 'fwd66a605 (forwarder to 0x4ccf60, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66a605, note='u69 forwarder; target 0x4ccf60 is a GUESS hook')

def _g66aec0(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x108)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66aec0, 'fwd66aec0 (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66aec0, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g66bdc0(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x90)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66bdc0, 'fwd66bdc0 (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66bdc0, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g66bdcb(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x110)
    val = c.rng.getrandbits(32)
    e.hook(0x4cbec0, lambda e, res: (e.calllog.append(('tgt4cbec0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66bdcb, 'fwd66bdcb (forwarder to 0x4cbec0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66bdcb, note='u69 forwarder; target 0x4cbec0 is a GUESS hook')

def _g66da80(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x2c)
    val = c.rng.getrandbits(32)
    e.hook(0x42ba10, lambda e, res: (e.calllog.append(('tgt42ba10', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66da80, 'fwd66da80 (forwarder to 0x42ba10, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66da80, note='u69 forwarder; target 0x42ba10 is a GUESS hook')

def _g66de40(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x1c)
    val = c.rng.getrandbits(32)
    e.hook(0x5a5440, lambda e, res: (e.calllog.append(('tgt5a5440', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66de40, 'fwd66de40 (forwarder to 0x5a5440, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66de40, note='u69 forwarder; target 0x5a5440 is a GUESS hook')

def _g66de48(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    exp = ebp + (-0x1c)
    val = c.rng.getrandbits(32)
    e.hook(0x4ff9d0, lambda e, res: (e.calllog.append(('tgt4ff9d0', int(e.reg('ecx') == exp))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66de48, 'fwd66de48 (forwarder to 0x4ff9d0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66de48, note='u69 forwarder; target 0x4ff9d0 is a GUESS hook')
