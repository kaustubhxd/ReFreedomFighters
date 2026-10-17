"""specs_s250.py - ladder thread batch 250: ZFFHERO::CopyDataBlock. DBLK accessors, GameEntity, operator new, the base
ZPlayer::CopyDataBlock and the multiplayer manager are logging stubs (other owners verified them); the port's calls to them
are compared on what they asked for."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _cdb(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    mgr = K.rnd(c, 0x40)
    mp = r.choice([0, 1, 1])
    team_val = r.getrandbits(32) & 0x1f if r.random() < 0.5 else r.choice([0, 1, 2, 3, 4, 5, 6, 31, 32, 33])
    tv = {'v': team_val}

    def mgr90(e2, a):
        e2.w8(a[1], mp)
        e2.calllog.append(('mgr90', K.nostack(a[0]), K.nostack(a[1])))
        return 0, None, None

    def mgr88(e2, a):
        e2.w32(a[1], tv['v'])
        e2.calllog.append(('mgr88', a[0], K.nostack(a[1])))
        return 0, None, None
    e.w32(mgr, K.vt(c, 'mpmgr', {0x88: (2, mgr88), 0x90: (2, mgr90)}, nslots=0x100))
    e.w32(d, K.vt(c, 'database', {0x134: (0, lambda e2, a: (mgr, None, None)),
                                  0x58: (1, lambda e2, a: ((a[0] * 3 + 9) & 0xffffffff, None, None))}, nslots=0x100))
    # DBLK accessors: Get writes a value through the out pointer; GetType returns the block type
    btype = r.choice([3, 8, 8, 1, 3, 0])
    getv = r.choice([0, 1, 2, 3, 4, 5, r.getrandbits(32)])

    def get_u(e2, res):
        e2.w32(e2.arg32(0), getv)
        e2.calllog.append(('DBLK::Get', e2.reg('ecx'), K.nostack(e2.arg32(0)), e2.arg32(1)))
        e2.ret(argbytes=8)
    e.hook(0x4e12e0, get_u)
    e.hook(0x4e11e0, get_u)

    def gettype(e2, res):
        e2.calllog.append(('DBLK::GetType', e2.reg('ecx')))
        e2.ret(eax=btype, argbytes=0)
    e.hook(0x4e1600, gettype)

    def nextb(e2, res):
        e2.calllog.append(('DBLK::NextBlock', e2.reg('ecx')))
        e2.ret(argbytes=0)
    e.hook(0x4e1b30, nextb)

    def base(e2, res):
        e2.calllog.append(('ZPlayer::CopyDataBlock', e2.reg('ecx'), K.nostack(e2.arg32(0))))
        e2.ret(argbytes=4)
    e.hook(0x482800, base)

    def ent_ctor(e2, res):
        e2.calllog.append(('GameEntity::ctor', K.nostack(e2.reg('ecx')), K.nostack(e2.arg32(0)), e2.arg32(1)))
        e2.ret(eax=e2.reg('ecx'), argbytes=8)
    e.hook(0x59d330, ent_ctor)

    def ent_team(e2, res):
        e2.calllog.append(('SetEntityTeam', K.nostack(e2.reg('ecx')), e2.arg32(0)))
        e2.ret(argbytes=4)
    e.hook(0x59d430, ent_team)

    def newh(e2, res):
        p = K.rnd(c, 0x40)
        e2.calllog.append(('operator new', e2.arg32(0)))
        e2.ret(eax=p, argbytes=0)
    e.hook(0x41e290, newh)

    self_ = K.rnd(c, 0xa00)
    e.w32(self_ + 0x684, r.getrandbits(32))
    blk = K.rnd(c, 0x40)
    return [self_, blk]


S(0x590620, 'ZFFHERO::CopyDataBlock', 'thiscall', None, ret=None, gen=_cdb, note='batch250')
