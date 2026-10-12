"""specs_s732.py - soldier AI batch 732: ZFFActor::RemoveFromSquad, AddToSquad and SetRecruitMode. The actor's squad (+0x921) is
a random pointer in about half the cases. SSquad::RemoveMember (0x58a360), SSquad::AddMember (0x5898c0, bool result) and the
marker calls AddActorActionMarker (0x598e10) and RemoveActorActionMarker (0x59a850) are hooked and log their arguments.
SetRecruitMode gets a global list of 0..5 actors (gl+0x40c, count at gl+0x408) and a hero, each with a +0x54 block whose
+4 dword is a class id (drawn from 0..2 so the same-class test runs both ways) and a +0x852 marker object. The mode is 0..3
(the table at 0x6adebc / 0x6adeb8 is exe data and is read as is)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _logger(e):
    return lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))


def _rm_hook_setup(c, e, log):
    def h_rm(em, r):
        log('squad', 0x58a360, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.hook(0x58a360, h_rm)
    add_res = c.rng.choice([0, 1])

    def h_add(em, r):
        log('squad', 0x5898c0, (em.arg32(0),))
        em.ret(eax=add_res, argbytes=4)
    e.hook(0x5898c0, h_add)


def _squad_rm(c):
    e = c.emu
    log = _logger(e)
    _rm_hook_setup(c, e, log)
    self_ = _rnd(c, 0x940)
    squad = _rnd(c, 0x40)
    e.w32(self_ + 0x921, squad if c.rng.random() < 0.5 else 0)
    return [self_]


def _squad_add(c):
    e = c.emu
    log = _logger(e)
    _rm_hook_setup(c, e, log)
    self_ = _rnd(c, 0x940)
    squad = _rnd(c, 0x40)
    return [self_, squad]


def _recruit(c):
    e = c.emu
    log = _logger(e)

    def h_add(em, r):
        log('mcl', 0x598e10, (em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    def h_rem(em, r):
        log('mcl', 0x59a850, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    e.hook(0x598e10, h_add)
    e.hook(0x59a850, h_rem)

    gl = _rnd(c, 0x2000)
    e.w32(0x7003b8, gl)
    n = c.rng.randint(0, 5)
    e.w32(gl + 0x408, n)

    def make_actor():
        blk = _rnd(c, 0x20)
        cls = _rnd(c, 0x20)
        e.w32(cls + 4, c.rng.randint(0, 2))
        e.w32(blk + 0x54, cls)
        a = _rnd(c, 0x900)
        e.w32(a + 0x54, blk)
        e.w32(a + 0x852, _rnd(c, 0x20))
        return a

    actors = [make_actor() for _ in range(n)]
    for i, a in enumerate(actors):
        e.w32(gl + 0x40c + 4 * i, a)

    hero = make_actor()
    self_ = _rnd(c, 0x940)
    e.w32(self_ + 0x92e, hero if c.rng.random() < 0.5 else 0)
    mode = c.rng.choice([0, 1, 2, 3, 4, 5])     # table class values: 2, 0, 0, 0, 2, 1 (modes 0..5)
    flag = 1 if c.rng.random() < 0.8 else 0
    hero_arg = hero if c.rng.random() < 0.5 else 0
    t = struct.unpack('<f', struct.pack('<f', c.rng.uniform(-2.0, 4.0)))[0]
    tbits = struct.unpack('<I', struct.pack('<f', t))[0]
    return [self_, mode, flag, hero_arg, tbits]


S(0x5a2860, 'ZFFActor::RemoveFromSquad', 'thiscall', None, ret=None, gen=_squad_rm, note='b732 [medium]; RemoveMember hooked')
S(0x59dce0, 'ZFFActor::AddToSquad', 'thiscall', None, ret=None, gen=_squad_add, note='b732 [medium]; AddMember hooked')
S(0x5a2e20, 'ZFFActor::SetRecruitMode', 'thiscall', None, ret=None, gen=_recruit,
  note='b732 [high]; marker add and remove hooked; global actor list in gl+0x40c')
