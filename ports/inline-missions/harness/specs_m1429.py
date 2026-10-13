"""specs_m1429.py - batch 1429: ZObjectives::Command. Unnamed slots stubbed by number; the 0x198 formatters are
stubs that write a fixed string into their buffer (they run on the port and the original alike).
ZBaseMap::Command is hooked."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402


def formatter(c):
    """slot 0x198 (this, a, buf, fmt, s): writes 'X' + s into buf (4 stack args; ret 0x10)."""
    def h(e, r):
        esp = e.reg('esp')
        buf = e.r32(esp + 12)
        s = e.r32(esp + 16)
        text = b'Z'
        k = 0
        while True:
            b = e.r8(s + k)
            if b == 0:
                break
            text += bytes([b])
            k += 1
        e.wbytes(buf, text + b'\0')
        e.ret(eax=0, argbytes=0)   # caller-cleaned: the original adds 16 to esp after the call
    return c.emu.stub_fn('formatter 0x198', h)


def g_cmd(c):
    self_ = rnd(c, 0x400)
    zone = rnd(c, 0x80)
    zone_bytes = c.rng.choice([b'C01A', b'C02A', b'C02RB', b'', b'C05A'])
    c.emu.wbytes(zone, zone_bytes + b'\0')
    holder = rnd(c, 0x80)
    c.emu.w32(holder + 0x48, zone)
    c.emu.w32(self_ + 0x94, holder)
    win = obj(c, 0x40, {0x284: stub(c, 1, this=True), 0x2a0: stub(c, 1, this=True)})
    c.emu.w32(self_ + 0x18c, win)
    rc = obj(c, 0x30, {0: stub(c, 2, this=True, skip=(0, 1), ret=cstr(c, 'Text'))})   # arguments are stack buffers in one call
    fmt_fn = formatter(c)
    a_vt = obj(c, 0x40, {0x198: fmt_fn})
    b_vt = obj(c, 0x40, {0x198: fmt_fn})
    sys_obj = obj(c, 0x200, {0x190: stub(c, 0, this=True, rets=[a_vt, b_vt, a_vt, b_vt])})
    mgr = obj(c, 0xb00, {0x114: stub(c, 4, this=True, rets=[0xe6]), 0x58: stub(c, 1, this=True, ret=0)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x6f, c.rng.getrandbits(32))
    c.emu.w32(sysi, c.emu.r32(sys_obj))
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(mgr + 0xae4, rc)
    logger(c, nargs=2)
    hook_stub(c, 0x573860, 2, this=True, ret=c.rng.getrandbits(32))
    data = zone if c.rng.random() < 0.85 else 0
    msg = c.rng.choice([0xe6, 0xe6, 0xe5]) | (c.rng.getrandbits(16) << 16)
    return [self_, msg, data]


S(0x5779a0, 'ZObjectives::Command', 'thiscall', ret='eax', gen=g_cmd)
