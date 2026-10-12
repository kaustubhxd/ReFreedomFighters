"""specs_s244.py - area 22, batch244 (src/batch244.cpp): ZActor::ActivateBaseMove, ZActorIf::BeamActorToRef,
CActionController::AddEvaluator. _CIfmod is the area-25 fprem stub; out-pointer vtable callees are Python handlers that
fill the block and log its contents (never the stack address); new is the shared bump allocator."""
import struct
from pilot import S
import out_stubs as os_
from helpers22 import _rnd, _multi_vt, _hk, _log_world, _pyvt, _install_fmod


def _r(c):
    return c.rng.getrandbits(32)


def _f32bits(c):
    k = c.rng.random()
    if k < 0.7:
        return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0]
    return _r(c)


def _g_477740(c):
    e = c.emu
    self_ = _rnd(c, 0x800)
    cur = _r(c)
    e.w32(self_ + 0x650, cur)
    e.w32(self_ + 0x755, _f32bits(c))
    hdr_base = _rnd(c, 0x200)
    off = c.rng.randint(1, 0x80) * 4
    h = hdr_base + off
    for o in (0x5c, 0x60, 0x64, 0x6c):
        e.w32(h + o, c.rng.choice([c.rng.randint(-3000, 3000), _r(c), 0, 1]))
    rec = _rnd(c, 8)
    e.w32(rec, off)
    e.w32(rec + 4, c.rng.choice([8, 0, _r(c)]))
    ret5a8 = c.rng.choice([rec, rec, rec, 0])
    e.w32(self_, _multi_vt(c, {0x5a8: (lambda em, a, v=ret5a8: (v, None), 1), 0x268: (lambda em, a: (0, None), 2)}))
    db = _rnd(c, 0x80)
    e.w32(db + 0x44, hdr_base)
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    _install_fmod(c)
    e.mu.ctl_flush_tb()
    idv = c.rng.choice([cur, cur, _r(c)])
    return [self_, idv, c.rng.choice([0, 1])]


def _g_5063d0(c):
    e = c.emu
    _log_world(c, pslot=0x30)
    blk = bytes(c.rng.getrandbits(8) for _ in range(0x24))
    pos = bytes(c.rng.getrandbits(8) for _ in range(0xc))

    def fill(em, r, blk=blk, pos=pos):
        em.calllog.append(('tgt.0x80', 0x80, None, ()))
        em.wbytes(em.arg32(0), blk)
        em.wbytes(em.arg32(1), pos)
        em.ret(eax=0, argbytes=8)

    def use(em, r):
        em.calllog.append(('actor.0x370', 0x370, None, (em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 0xc))))
        em.ret(eax=0, argbytes=8)
    nameobj = _rnd(c, 0x10)
    actor = _rnd(c, 0x40)
    e.w32(actor, _pyvt(c, {0x370: use,
                           0x20: lambda em, r, v=nameobj: (em.calllog.append(('actor.0x20', 0x20, None, ())),
                                                           em.ret(eax=v))}))
    target = _rnd(c, 0x40)
    e.w32(target, _pyvt(c, {0x80: fill}))
    ids = [_r(c), _r(c)]
    tgt_ret = c.rng.choice([target, target, target, 0])
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, m={ids[0]: actor, ids[1]: tgt_ret}: (m.get(a[0], 0), None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    w0, w1 = _rnd(c, 8), _rnd(c, 8)
    e.w32(w0, ids[0])
    e.w32(w1, ids[1])
    _hk(c, 0x5003d0, '5003d0', 1, eax=lambda em: w0 if em.arg32(0) == 0 else w1)
    params = _rnd(c, 0x10)
    e.w32(params + 4, _rnd(c, 0x20))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x20), params]


def _g_49fa80(c):
    e = c.emu
    _log_world(c)
    self_ = _rnd(c, 0x8c0)
    e.w32(self_ + 0x48, c.rng.choice([0, 1, 2, 3, 3, 4, 5, 0xffffffff, 0xfffffffe, 0x7fffffff, 0x40000000 + c.rng.getrandbits(29)]))   # signed compare: -1, -2 index inside the object; large negatives would fault on both sides, so none
    pool = e.alloc(0x2000, 16)
    e.wbytes(pool, bytes(0x2000))
    os_.bump_alloc(c, pool, 0x41e290)
    _hk(c, 0x49f670, '49f670', 0, eax=lambda em: em.reg('ecx'))
    e.mu.ctl_flush_tb()
    return [self_, _r(c)]


S(0x477740, 'ZActor::ActivateBaseMove', 'thiscall', None, ret='al', gen=_g_477740,
  note='batch244; vt 0x5a8 record, anim header ratios, _CIfmod (fprem stub), vt 0x268', nan_heap=True)
S(0x5063d0, 'ZActorIf::BeamActorToRef', 'thiscall', None, ret=None, gen=_g_5063d0,
  note='batch244; cookie not reproduced; out-pointer blocks logged by content')
S(0x49fa80, 'CActionController::AddEvaluator', 'thiscall', None, ret=None, gen=_g_49fa80,
  note='batch244; SEH frame and cookie not reproduced; new = bump stub, ctor hooked')
