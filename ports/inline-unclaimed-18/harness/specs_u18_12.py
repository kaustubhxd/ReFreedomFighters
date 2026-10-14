"""specs_u18_12.py - core-todo residue 17 (unclaimed-18 thread). DBREAD readers are other threads' work: hooked here."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _dbhooks(c):
    r = c.rng
    e = c.emu
    e.hook(0x4e5e40, lambda e, res: (e.calllog.append(('DBREAD::u16', e.arg32(0) if False else e.reg('ecx'))), e.ret(eax=r.getrandbits(16), argbytes=0)))
    e.hook(0x4e5e60, lambda e, res: (e.calllog.append(('DBREAD::u32', e.reg('ecx'))), e.ret(eax=r.getrandbits(32), argbytes=0)))
    e.hook(0x4e6330, lambda e, res: (e.calllog.append(('GetRefTab', e.reg('ecx'), e.arg32(0))), e.ret(argbytes=4)))


def _rmc(c):
    _dbhooks(c)
    return [rnd(c, 0x80), rnd(c, 0x40)]


S(0x4b8590, 'ZRelayMessage::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_rmc,
  note='u18 core residue 17; DBREAD readers are hooks (other threads)')


def _rpc(c):
    r = c.rng
    e = c.emu
    _dbhooks(c)
    sysobj = rnd(c, 0x2000)
    e.w32(0x70039c, sysobj)
    eng = obj(e, 'engine', 0x40, {0x58: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0],)))}, nslots=0x5c // 4)
    e.w32(sysobj + 0x9b, eng)
    return [rnd(c, 0x80), rnd(c, 0x40)]


S(0x5c4150, 'ZRepositionCharacter::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_rpc,
  note='u18 core residue 17; DBREAD readers and GetRefTab are hooks')
