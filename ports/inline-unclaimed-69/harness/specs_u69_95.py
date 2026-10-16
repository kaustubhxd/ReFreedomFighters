"""specs_u69_95.py - area 69, residue-8 forwarders (listed separately). Frame buffer through ('regs', ['ebp']); the object sits at [ebp+D];
each target is a GUESS hook that logs whether ECX is the object and returns a random eax. The targets are not verified bodies."""
from pilot import S
from ckit import rnd


def _g6645c0(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x433f30, lambda e, res: (e.calllog.append(('tgt433f30', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x6645c0, 'fwd6645c0 (forwarder to 0x433f30, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g6645c0, note='u69 forwarder; target 0x433f30 is a GUESS hook')

def _g668581(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x14), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x4f6b20, lambda e, res: (e.calllog.append(('tgt4f6b20', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x668581, 'fwd668581 (forwarder to 0x4f6b20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g668581, note='u69 forwarder; target 0x4f6b20 is a GUESS hook')

def _g668a81(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x14), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x4f6b20, lambda e, res: (e.calllog.append(('tgt4f6b20', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x668a81, 'fwd668a81 (forwarder to 0x4f6b20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g668a81, note='u69 forwarder; target 0x4f6b20 is a GUESS hook')

def _g668d00(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x4f6b20, lambda e, res: (e.calllog.append(('tgt4f6b20', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x668d00, 'fwd668d00 (forwarder to 0x4f6b20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g668d00, note='u69 forwarder; target 0x4f6b20 is a GUESS hook')

def _g669480(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x4d4d20, lambda e, res: (e.calllog.append(('tgt4d4d20', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x669480, 'fwd669480 (forwarder to 0x4d4d20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g669480, note='u69 forwarder; target 0x4d4d20 is a GUESS hook')

def _g669840(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x449d80, lambda e, res: (e.calllog.append(('tgt449d80', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x669840, 'fwd669840 (forwarder to 0x449d80, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g669840, note='u69 forwarder; target 0x449d80 is a GUESS hook')

def _g66a740(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x534be0, lambda e, res: (e.calllog.append(('tgt534be0', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66a740, 'fwd66a740 (forwarder to 0x534be0, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66a740, note='u69 forwarder; target 0x534be0 is a GUESS hook')

def _g66c400(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x4f6b20, lambda e, res: (e.calllog.append(('tgt4f6b20', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66c400, 'fwd66c400 (forwarder to 0x4f6b20, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66c400, note='u69 forwarder; target 0x4f6b20 is a GUESS hook')

def _g66e5c0(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x616a40, lambda e, res: (e.calllog.append(('tgt616a40', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66e5c0, 'fwd66e5c0 (forwarder to 0x616a40, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66e5c0, note='u69 forwarder; target 0x616a40 is a GUESS hook')

def _g66ed40(c):
    e = c.emu
    buf = rnd(c, 0x5000)
    ebp = buf + 0x4f00
    obj = rnd(c, 0x800)
    e.w32(ebp + (-0x10), obj)
    val = c.rng.getrandbits(32)
    e.hook(0x64f380, lambda e, res: (e.calllog.append(('tgt64f380', int(e.reg('ecx') == obj))), e.ret(eax=val, argbytes=0)))
    return [ebp]

S(0x66ed40, 'fwd66ed40 (forwarder to 0x64f380, GUESS target)', ('regs', ['ebp']), None, ret='eax', gen=_g66ed40, note='u69 forwarder; target 0x64f380 is a GUESS hook')
